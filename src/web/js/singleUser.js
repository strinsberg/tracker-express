var params = new URLSearchParams(window.location.search);

fetch("http://localhost:1234/trackEx/users?id=" + params.get("id"))
.then(response => {
    return response.json();
})
.then(data => {
    var user = data.response;
    document.getElementById("name").innerHTML = user.name;
    document.getElementById("blurb").innerHTML = user.blurb;
    var picNum = user.pic;
    if (picNum > 5 || picNum < 0) {
        picNum = -1;
    }
    document.getElementById("picture").src = "images/" + user.pic + ".jpg";
});

function editUser() {
    window.open("addUser.html?id=" + params.get("id"), "_self");
}

async function deleteUser() {
    if (confirm("Are you sure you would like to delete this user?")) {
        const response = await fetch("http://localhost:1234/trackEx/users?id=" + params.get("id") + "&delete");
        window.open("users.html","_self");
    }
}
