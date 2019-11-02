async function postUser() {
  console.log("Activate POST User!!");

  const response = await fetch("http://localhost:1234/trackEx/users", {
    method: "POST",
    headers: {
      "Accept": "*/*",
      "Content-Type": "text/plain"
    },
    body: JSON.stringify({name: "Test BillyBob", blurb: "Some info about me",
      pic: 0})
  });

  // Not doing anything with the response as there is some issue with the
  // Service not returning an actual response for the POST methods.
  console.log('Success', response);

}
