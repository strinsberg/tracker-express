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

fetch("http://localhost:1234/trackEx/comments")
.then(response => {
    console.log(response);
    return response.json();
})
.then(data => {
    var table = document.getElementById("comment_table");
    data.response.forEach(comment => {
        var com = JSON.parse(comment);
        var row = table.insertRow(-1);
        
        var user = row.insertCell(0);
        var text = row.insertCell(1);
        
        user.innerHTML = com.user_id;
        text.innerHTML = com.text;

        console.log("Comment:", com);
    });
}).catch(err => {
    console.error("Error:", err);
});


async function deleteIssue() {
    if (confirm("Are you sure you would like to delete this issue?")) {
        fetch("http://localhost:1234/trackEx/issues?id=" + params.get("id") + "&delete")
        window.open("issues.html","_self");
    }
}

async function postComment() {
  values = {
    "text": document.getElementById("newComment").value,
    "issue_id": parseInt(params.get("id")),
    "user_id": parseInt(document.getElementById("userID").value)
  };
  //console.log(values);

  fetch("http://localhost:1234/trackEx/comments", {
    method: "POST",
    headers: {
      "Accept": "*/*",
      "Content-Type": "text/plain"
    },
    body: JSON.stringify(values),
  })
  
  //window.open("singleIssue.html?id=" + params.get("id"), "_self");
}
