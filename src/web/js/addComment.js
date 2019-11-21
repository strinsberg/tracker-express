var params = new URLSearchParams(window.location.search);

async function postComment() {
  values = {
    "text": document.getElementById("newComment").value,
    "issue_id": parseInt(params.get("id")),
    "user_id": parseInt(document.getElementById("userID").value)
  };
  //console.log(values);

  const response = await fetch("http://localhost:1234/trackEx/comments", {
    method: "POST",
    headers: {
      "Accept": "*/*",
      "Content-Type": "text/plain"
    },
    body: JSON.stringify(values),
  }).catch(err => {
    console.error("Error:", err);
  });
  
  console.log(response);
  window.open("singleIssue.html?id=" + params.get("id"), "_self");
}
