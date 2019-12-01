var params = new URLSearchParams(window.location.search);

if (params.has("id")) {
    fetch("http://localhost:1234/trackEx/users?id=" + params.get("id"))
    .then(response => {
        return response.json();
    })
    .then(data => {
        var user = data.response;
        
        document.getElementById("name").value = user.name;
        document.getElementById("blurb").value = user.blurb;
        document.getElementById("pic").value = user.pic;
    })
}

async function postUser() {
  var url = "http://localhost:1234/trackEx/users";
  if (params.has("id")) {
    url += "?id=" + params.get("id");
  }

  values = {
    "name": document.getElementById("name").value,
    "blurb": document.getElementById("blurb").value,
    "pic": parseInt(document.getElementById("pic").value),
  };
  console.log(values);

  const response = await fetch(url, {
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
  window.open("users.html","_self");
}
