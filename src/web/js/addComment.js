var params = new URLSearchParams(window.location.search);

fetch("http://localhost:1234/trackEx/users")
.then(response => {
console.log(response);
return response.json();
})
.then(data => {
var userID = document.getElementById("userID");
//Dynamically update HTML elements for creator and assignee.
        data.response.forEach(user => {
        var user_data = JSON.parse(user);
        var opt = document.createElement("option");
        opt.value = user_data.id;
        opt.innerHTML = user_data.name;
        userID.appendChild(opt);
        })
})
.catch(err => {
console.error("Error:", err);
});
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
