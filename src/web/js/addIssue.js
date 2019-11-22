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
        var user_data = JSON.parse(user);
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


async function postIssue() {
  values = {
    "title": document.getElementById("title").value,
    "description": document.getElementById("description").value,
    "assignee": parseInt(document.getElementById("assignee").value),
    "creator": parseInt(document.getElementById("creator").value),
    "priority": parseInt(document.getElementById("priority").value),
    "tags": document.getElementById("tags").value.split(',').map(
        item => {return item.trim()}),
  }
  console.log('values', values);

  const response = await fetch("http://localhost:1234/trackEx/issues", {
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
