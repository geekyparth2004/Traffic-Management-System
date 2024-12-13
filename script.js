document.getElementById('uploadForm').addEventListener('submit', async (e) => {
    e.preventDefault();

    const fileInput = document.getElementById('imageInput');
    const loader = document.getElementById('loader');
    const outputImage = document.getElementById('outputImage');
    outputImage.style.display = 'none'; // Hide previous output image

    if (fileInput.files.length === 0) {
        alert('Please upload an image.');
        return;
    }

    const formData = new FormData();
    formData.append('file', fileInput.files[0]);

    loader.style.display = 'block'; // Show loader
    try {
        const response = await fetch('/process_image', { // Match the Python endpoint
            method: 'POST',
            body: formData,
        });

        if (response.ok) {
            const blob = await response.blob();
            outputImage.src = URL.createObjectURL(blob);
            outputImage.style.display = 'block';
        } else {
            const errorData = await response.json();
            alert(errorData.error || 'An error occurred while processing the image.');
        }
    } catch (error) {
        alert('Error uploading the file. Please try again.');
    } finally {
        loader.style.display = 'none'; // Hide loader
    }
});
