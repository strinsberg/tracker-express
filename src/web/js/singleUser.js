var params = new URLSearchParams(window.location.search);

fetch("http://localhost:1234/trackEx/users?id=" + params.get("id"))
.then(response => {
    return response.json();
})
.then(data => {
    var user = JSON.parse(data.response);
    document.getElementById("name").innerHTML = user.name;
    document.getElementById("blurb").innerHTML = "About: " + user.blurb;
    document.getElementById("picture").innerHTML = user.pic;
});

//not working properly yet
//i can confirm the handler works because I tested it with curl
async function deleteUser() {
    if (confirm("Are you sure you would like to delete this user?")) {
        const response = await fetch("http://localhost:1234/trackEx/users?id=" + params.get("id") + "&delete");
        window.open("users.html","_self");
    }
}
