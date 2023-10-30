document.getElementById('imageInput').addEventListener('change', function (e) {
    const image = document.getElementById('uploadedImage');
    const customText = document.getElementById('customText');
    const customTextInput = document.getElementById('customTextInput');
  
    // Display custom text on the image
    customText.textContent = customTextInput.value;
  
    const file = e.target.files[0];
  
    if (file) {
      const reader = new FileReader();
  
      reader.onload = function (e) {
        image.src = e.target.result;
      };
  
      reader.readAsDataURL(file);
    }
  });
  
  document.getElementById('generatePDF').addEventListener('click', function () {
    const image = document.getElementById('uploadedImage');
    const customText = document.getElementById('customText');
    const customTextInput = document.getElementById('customTextInput');
  
    // Display custom text on the image
    customText.textContent = customTextInput.value;
  
    // Create a PDF document
    const doc = new pdfjs.Document();
  
    // Add an image to the PDF
    doc.image(image, 10, 10, { width: 200 });
  
    // Add custom text
    doc.text(customText.textContent, 10, 220);
  
    // Generate PDF and allow download
    doc.output('dataurlnewwindow');
  });
  
  document.getElementById('downloadImage').addEventListener('click', function () {
    const imageContainer = document.getElementById('imageContainer');
    const customText = document.getElementById('customText');
    const customTextInput = document.getElementById('customTextInput');
  
    // Display custom text on the image
    customText.textContent = customTextInput.value;
  
    // Use html2canvas to capture the modified image and text
    html2canvas(imageContainer).then(function (canvas) {
      // Create an image URL from the canvas
      const imgData = canvas.toDataURL('image/png');
  
      // Create a link to download the image
      const link = document.createElement('a');
      link.href = imgData;
      link.download = 'modified_image.png';
  
      // Trigger a click event to download the image
      link.click();
    });
  });
  