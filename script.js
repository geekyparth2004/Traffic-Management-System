document.getElementById('uploadForm').addEventListener('submit', async (e) => {
    e.preventDefault();

    const fileInput = document.getElementById('imageInput');
    if (fileInput.files.length === 0) {
        alert('Please upload an image.');
        return;
    }

    const formData = new FormData();
    formData.append('file', fileInput.files[0]);

    try {
        const response = await fetch('/upload', {
            method: 'POST',
            body: formData,
        });

        if (response.ok) {
            const blob = await response.blob();
            const outputImage = document.getElementById('outputImage');
            outputImage.src = URL.createObjectURL(blob);
            outputImage.style.display = 'block';
        } else {
            const errorData = await response.json();
            alert(errorData.error || 'An error occurred.');
        }
    } catch (error) {
        alert('Error uploading the file. Please try again.');
    }
});
