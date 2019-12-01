var params = new URLSearchParams(window.location.search);

//Fetch all users from the API
fetch("http://localhost:1234/trackEx/users")
.then(response => {
console.log(response);
return response.json();
})
.then(data => {
var creator = document.getElementById("creator");
var assignee = document.getElementById("assignee");

//Dynamically update HTML elements for creator and assignee.
        data.response.forEach(user => {
        var user_data = user;
        var opt = document.createElement("option");
        opt.value = user_data.id;
        opt.innerHTML = user_data.name;
        creator.appendChild(opt);
        var opt2 = document.createElement("option");
        opt2.value = user_data.id;
        opt2.innerHTML = user_data.name;
        assignee.appendChild(opt2);
        })
})
.catch(err => {
console.error("Error:", err);
});

// If updateing get the issue and fill all the fields
if (params.has("id")) {
    fetch("http://localhost:1234/trackEx/issues?id=" + params.get("id"))
    .then(response => {
        return response.json();
    })
    .then(data => {
        console.log(data.response);
        var iss = data.response;
        
        document.getElementById("title").value = iss.title;
        document.getElementById("description").value = iss.description;
        document.getElementById("assignee").value = iss.assignee;
        
        document.getElementById("creator").value = iss.creator;
        document.getElementById("creator_div").hidden = true;
        
        document.getElementById("priority").value = iss.priority;
        document.getElementById("tags").value = iss.tags.join(", ");

        document.getElementById("status_div").hidden = false;
        document.getElementById("status").value = iss.status;
    }).catch(err => {
        console.error("Error:", err);
    });
}

async function postIssue() {
  var url = "http://localhost:1234/trackEx/issues";
  if (params.has("id")) {
    url += "?id=" + params.get("id");
  }

  values = {
    "title": document.getElementById("title").value,
    "description": document.getElementById("description").value,
    "assignee": parseInt(document.getElementById("assignee").value),
    "creator": parseInt(document.getElementById("creator").value),
    "priority": parseInt(document.getElementById("priority").value),
    "tags": document.getElementById("tags").value.split(',').map(
        item => {return item.trim()}),
    "status": parseInt(document.getElementById("status").value),
  }
  console.log('values', values);

  const response = await fetch(url, {
    method: "POST",
    headers: {
      "Accept": "*/*",
      "Content-Type": "text/plain"
    },
    body: JSON.stringify(values),
  });

  // still need to do something to deal with the response properly
  console.log('Success', response);
  window.open("issues.html","_self");
}
