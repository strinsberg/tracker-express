async function postUser() {
  values = {
    "name": document.getElementById("name").value,
    "blurb": document.getElementById("blurb").value,
    "pic": parseInt(document.getElementById("pic").value),
  };
  console.log(values);

  const response = await fetch("http://localhost:1234/trackEx/users", {
    method: "POST",
    headers: {
      "Accept": "*/*",
      "Content-Type": "text/plain"
    },
    body: JSON.stringify(values),
  });

  // Not doing anything with the response as there is some issue with the
  // Service not returning an actual response for the POST methods.
  console.log('Success', response);

}
