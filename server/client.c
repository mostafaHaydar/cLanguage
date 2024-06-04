#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <wininet.h>
#include <winuser.h>

#pragma comment(lib, "wininet.lib")

#define BUFFER_SIZE 1024
void getLinksFromHTMLContent() {

  FILE *pFile = fopen("client.html", "r");
  char response[10000];
  int i = 0;
  int ch;
  while ((ch = fgetc(pFile)) != EOF && i < sizeof(response) - 1) {
    response[i++] = (char)ch;
  }
  response[i] = '\0';
  fclose(pFile);

  char links[100][1000] = {0};
  int lastLinkId = 0;

  char imgDelimiter[6];
  char src[6] = "src=\"\0";

  char hrefDelimiter[7];
  char href[7] = "href=\"\0";

  for (size_t i = 0; i < strlen(response); i++) {
    if (i < 4) {

      for (size_t d = 0; d < 5; d++) {
        imgDelimiter[d] = response[d];
      }
      imgDelimiter[5] = 0;

      for (size_t d = 0; d < 6; d++) {
        hrefDelimiter[d] = response[d];
      }
      hrefDelimiter[6] = 0;

    } else {

      for (size_t d = 0; d < 4; d++) {
        imgDelimiter[d] = imgDelimiter[d + 1];
      }
      imgDelimiter[4] = response[i + 1];
      imgDelimiter[5] = 0;

      for (size_t d = 0; d < 5; d++) {
        hrefDelimiter[d] = hrefDelimiter[d + 1];
      }
      hrefDelimiter[5] = response[i + 1];
      hrefDelimiter[6] = 0;
    }
    if (!strcmp(imgDelimiter, src)) {
      int count = 0;
      for (size_t t = i + 2; t < i + 2 + 1000; t++) {
        if (response[t] == '\"') {
          break;
        }
        links[lastLinkId][count++] = response[t];
      }
      lastLinkId++;
    }

    if (!strcmp(hrefDelimiter, href)) {
      int count = 0;
      for (size_t t = i + 2; t < i + 2 + 1000; t++) {
        if (response[t] == '\"') {
          break;
        }
        links[lastLinkId][count++] = response[t];
      }
      lastLinkId++;
    }
  }
  for (size_t i = 0; i < 100; i++) {
    printf("%s\n", links[i]);
    if(links[i][0]==0){
      break;
    }
  }
}

int main() {
  HINTERNET hInternet =
      InternetOpen("HTTP Client", INTERNET_OPEN_TYPE_DIRECT, NULL, NULL, 0);
  if (hInternet == NULL) {
    fprintf(stderr, "Error: InternetOpen failed\n");
    return 1;
  }

  HINTERNET hConnect = InternetOpenUrl(hInternet, "https://ajircom.com/", NULL,
                                       0, INTERNET_FLAG_NO_CACHE_WRITE, 0);
  if (hConnect == NULL) {
    fprintf(stderr, "Error: InternetOpenUrl failed\n");
    InternetCloseHandle(hInternet);
    return 1;
  }

  FILE *file = fopen("client.html", "wb");
  if (file == NULL) {
    fprintf(stderr, "Error: Failed to open file\n");
    InternetCloseHandle(hConnect);
    InternetCloseHandle(hInternet);
    return 1;
  }

  char buffer[BUFFER_SIZE];
  DWORD bytesRead;
  while (InternetReadFile(hConnect, buffer, sizeof(buffer), &bytesRead) &&
         bytesRead > 0) {
    fwrite(buffer, 1, bytesRead, file);
  }

  fclose(file);
  InternetCloseHandle(hConnect);
  InternetCloseHandle(hInternet);
  getLinksFromHTMLContent();
  return 0;
}
