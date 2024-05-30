#include <stdio.h>
#include <windows.h>
#include <wininet.h>

#pragma comment(lib, "wininet.lib")

#define BUFFER_SIZE 1024

int main() {
  HINTERNET hInternet =
      InternetOpen("HTTP Client", INTERNET_OPEN_TYPE_DIRECT, NULL, NULL, 0);
  if (hInternet == NULL) {
    fprintf(stderr, "Error: InternetOpen failed\n");
    return 1;
  }

  HINTERNET hConnect = InternetOpenUrl(hInternet, "http://ajircom.com/", NULL,
                                       0, INTERNET_FLAG_NO_CACHE_WRITE, 0);
  if (hConnect == NULL) {
    fprintf(stderr, "Error: InternetOpenUrl failed\n");
    InternetCloseHandle(hInternet);
    return 1;
  }

  FILE *file = fopen("test.html", "wb");
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
  return 0;
}
