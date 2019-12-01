var params = new URLSearchParams(window.location.search);


if (params.has("id")) {
    fetch("http://localhost:1234/trackEx/comments?id=" + params.get("id"))
    .then(response => {
        return response.json()
    })
    .then(data => {
        var text_box = document.getElementById("newComment");
        text_box.innerHTML = data.response.text;
    })
    .catch(err => {
    console.error("Error:", err);
    });
}

fetch("http://localhost:1234/trackEx/users")
.then(response => {
console.log(response);
return response.json();
})
.then(data => {
    var userID = document.getElementById("userID");

    data.response.forEach(user_data => {
    var opt = document.createElement("option");
    opt.value = user_data.id;
    opt.innerHTML = user_data.name;
    userID.appendChild(opt);
    })
    
    return userID;
})
.then(user_picker => {
    if (params.has("user")) {
        user_picker.value = params.get("user");
    }
})
.catch(err => {
console.error("Error:", err);
});


async function postComment() {
  var url = "http://localhost:1234/trackEx/comments";
  if (params.has("id")) {
    url += "?id=" + params.get("id");
  }

  values = {
    "text": document.getElementById("newComment").value,
    "issue_id": parseInt(params.get("issue")),
    "user_id": parseInt(document.getElementById("userID").value)
  };

  const response = await fetch(url, {
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
  window.open("singleIssue.html?id=" + params.get("issue"), "_self");
}
