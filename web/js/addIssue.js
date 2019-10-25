function postIssue() {
  console.log("Activate POST Issue!!");
  var b = {nothing: "try again"};
  fetch("http://localhost:1234/trackEx/issues") 
  .then(response => {
    return response.json();
  })
  .then(data => {
    console.log("Success:", JSON.stringify(data));
  })
  .catch(err => {
    console.error("Error:", err);
  });
}

