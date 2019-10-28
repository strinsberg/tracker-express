async function postIssue() {
  console.log("Activate POST Issue!!");

  const response = await fetch("http://localhost:1234/trackEx/issues", {
    method: "POST",
    mode: "no-cors",
    headers: {
      "Accept": "*/*",
      "Content-Type": "text/plain"
    },
    body: JSON.stringify({title: "test issue", "description":"some long ideas",
      "assignee": -1, "creator": -1, "priority": 1})
  });

  // Not doing anything with the response as there is some issue with the
  // Service not returning an actual response for the POST methods.
  console.log('Success', response);

}

