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

