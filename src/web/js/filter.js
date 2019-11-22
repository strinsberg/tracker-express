$(document).ready(function () {



    $('#datefilterfrom').on("change", filterRows);
    $('#datefilterto').on("change", filterRows);
    $('#projectfilter').on("change", filterProject);
    $('#servicefilter').on("change", filterService);
});

function filterRows() {
    var from = $('#datefilterfrom').val();
    var to = $('#datefilterto').val();

    if (!from && !to) { // no value for from and to
        return;
    }

    from = from || '1970-01-01'; // default from to a old date if it is not set
    to = to || '2999-12-31';

    var dateFrom = moment(from);
    var dateTo = moment(to);

    $('#testTable tr').each(function (i, tr) {
        var val = $(tr).find("td:nth-child(2)").text();
        var dateVal = moment(val, "DD/MM/YYYY");
        var visible = (dateVal.isBetween(dateFrom, dateTo, null, [])) ? "" : "none"; // [] for inclusive
        $(tr).css('display', visible);
    });
}
function filterProject() {
    let dumb = this.options.selectedIndex;
    dumb = this.options[dumb].innerHTML;
    var filter, table, tr, td, i;
    filter = dumb.toUpperCase();
    table = document.getElementById("issue_table");
    tr = table.getElementsByTagName("tr");
    for (i = 0; i < tr.length; i++) {
        td = tr[i].getElementsByTagName("td")[2];
        if (td) {
            if (td.innerHTML.toUpperCase().indexOf(filter) > -1) {
                tr[i].style.display = "table-row";
            } else {
                tr[i].style.display = "none";
            }
        }

    }
}

function filterService() {
    let dumb = this.options.selectedIndex;
    dumb = this.options[dumb].innerHTML;
    var filter, table, tr, td, i;
    filter = dumb.toUpperCase();
    table = document.getElementById("issue_table");
    tr = table.getElementsByTagName("tr");
    for (i = 0; i < tr.length; i++) {
        td = tr[i].getElementsByTagName("td")[3];
        if (td) {
            if (td.innerHTML.toUpperCase().indexOf(filter) > -1) {
                tr[i].style.display = "table-row";
            } else {
                tr[i].style.display = "none";
            }
        }

    }
}
