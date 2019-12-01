fetch("http://localhost:1234/trackEx/users")
    .then(response => {
    console.log(response);
    return response.json();
    })
    .then(data => {
        var table = document.getElementById("user_table");
        data.response.forEach(user => {
            var row = table.insertRow(-1);

            var id = row.insertCell(0);
            var name = row.insertCell(1);
            var pic = row.insertCell(2);
            id.innerHTML = user.id;
            name.innerHTML = '<a href="singleUser.html?id=' + user.id + '">' + user.name + '</a>';
            var image = document.createElement("img");
            image.src = "images/" + user.pic + ".jpg"
            image.height = 40;
            pic.appendChild(image);
        })
    })
    .catch(err => {
    console.error("Error:", err);
});
