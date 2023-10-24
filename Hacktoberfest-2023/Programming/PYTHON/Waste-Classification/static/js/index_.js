
$("document").ready(function () {
    $(function () {
        $('#myFile').click(function (event) {
            var par = document.getElementById("display-img")
            par.style.visibility = "hidden";
            par.src = "";
            par.alt = "";
            par.className = "img-thumbnail";
            document.getElementById("predictionCt").style.display = "None";

        });
    });
});

$("document").ready(function () {
    $(function () {
        $('#myFile').change(function (event) {
            var par = document.getElementById("display-img");
            par.style.visibility = "visible";
            par.src = URL.createObjectURL(event.target.files[0]);
            par.alt = event.target.files[0].name;
        });
    });
});

$(document).ready(function () {
    $("form").on('submit', function (event) {
        var form_data = new FormData($('#upload-file')[0]);
        $.ajax({
            type: 'POST',
            url: '/resultpage',
            data: form_data,
            contentType: false,
            cache: false,
            processData: false,
            beforeSend: function () {
                document.getElementById("myFile").disabled = true;
                document.getElementById("submission").disabled = true;

                var gif = document.getElementById("after");
                gif.style.visibility = "visible";

                var text = ["Processing", "Classifying", "Getting Result"];
                var counter = 0;
                var elem = document.getElementById("processing");
                var inst = setInterval(change, 2500);

                function change() {
                    elem.innerHTML = text[counter];
                    counter++;
                    if (counter >= text.length) {
                        counter = 0;
                    }
                }
            },
            success: function (data) {
                document.getElementById("myFile").disabled = false;
                document.getElementById("submission").disabled = false;
                var gif = document.getElementById("after");
                gif.style.visibility = "hidden";

                if (data.pred < 0) {
                    document.getElementById("predictionCt").className = "alert alert-success";
                    document.getElementById("display-img").className = "img-thumbnail border border-4 border-success";
                    $("#predictionCt").text(data.text).show();
                }
                else {
                    document.getElementById("predictionCt").className = "alert alert-danger";
                    document.getElementById("display-img").className = "img-thumbnail border border-4 border-danger";
                    $("#predictionCt").text(data.text).show();
                }
            },
            error: function (data) {
                alert("Please wait, or try again in a few minutes!");
                setTimeout(window.location.reload(), 2000);

            }
        });
        event.preventDefault();
    });
});
