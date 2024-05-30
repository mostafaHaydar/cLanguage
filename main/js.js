fetch("ajircom.com/").then(response => {
    console.log(response.status);
    // 200 →
    console.log(response.headers.get("Content-Type"));
    // text/plain →
   });
   