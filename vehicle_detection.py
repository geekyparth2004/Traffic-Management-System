import cv2
from darkflow.net.build import TFNet
import os

# Update options with correct paths and a meaningful threshold value
options = {
    'model': os.path.join('.', 'cfg', 'yolo.cfg'),  # Using os.path.join for cross-platform compatibility
    'load': os.path.join('.', 'bin', 'yolov2.weights'),
    'threshold': 0.3  # Minimum confidence factor
}

# Initialize the model
tfnet = TFNet(options)

# Define paths for input and output images
inputPath = os.path.join(os.getcwd(), "test_images")
outputPath = os.path.join(os.getcwd(), "output_images")

# Ensure output directory exists
if not os.path.exists(outputPath):
    os.makedirs(outputPath)

def detectVehicles(filename):
    global tfnet, inputPath, outputPath
    img = cv2.imread(os.path.join(inputPath, filename), cv2.IMREAD_COLOR)
    if img is None:
        print(f"Error reading image: {filename}")
        return

    # Perform detection
    result = tfnet.return_predict(img)
    for vehicle in result:
        label = vehicle['label']  # Extracting label
        if label in {"car", "bus", "bike", "truck", "rickshaw"}:  # Drawing box and writing label
            top_left = (vehicle['topleft']['x'], vehicle['topleft']['y'])
            bottom_right = (vehicle['bottomright']['x'], vehicle['bottomright']['y'])
            img = cv2.rectangle(img, top_left, bottom_right, (0, 255, 0), 3)  # Green box
            img = cv2.putText(img, label, (top_left[0], top_left[1] - 5), cv2.FONT_HERSHEY_COMPLEX, 0.5, (0, 0, 0), 1)

    # Save the output image
    outputFilename = os.path.join(outputPath, f"output_{filename}")
    cv2.imwrite(outputFilename, img)
    print('Output image stored at:', outputFilename)

# Process all images in the input directory
for filename in os.listdir(inputPath):
    if filename.lower().endswith((".png", ".jpg", ".jpeg")):
        detectVehicles(filename)

print("Done!")
