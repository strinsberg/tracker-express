var params = new URLSearchParams(window.location.search);

fetch("http://localhost:1234/trackEx/issues?id=" + params.get("id"))
.then(response => {
    return response.json();
})
.then(data => {
    var iss = JSON.parse(data.response);
    document.getElementById("title").innerHTML = iss.title;
    document.getElementById("description").innerHTML = iss.description;
    document.getElementById("status").innerHTML = "Status: " + iss.status;
    document.getElementById("assignee").innerHTML = "Assignee: " + iss.assignee;
    document.getElementById("creator").innerHTML = "Creator: " + iss.creator;
    document.getElementById("priority").innerHTML = "Priority: " + iss.priority;
    document.getElementById("tags").innerHTML = "Tags: " + iss.tags;
});

//not working properly yet
//i can confirm the handler works because I tested it with curl
async function deleteIssue() {
  const response = await fetch("http://localhost:1234/trackEx/issues?id=" + params.get("id"), {
    method: "DELETE",
    headers: {
      "Accept": "*/*",
      "Content-Type": "text/plain"
    },
    body: "",
  });
}
