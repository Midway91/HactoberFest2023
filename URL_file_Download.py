import requests

# URL of the file you want to download
file_url = 'https://example.com/path/to/file.zip'

# Local file path to save the downloaded file
local_file_path = '/path/to/local/directory/file.zip'

try:
    # Send a GET request to the URL
    response = requests.get(file_url, stream=True)

    # Check if the request was successful (HTTP status code 200)
    if response.status_code == 200:
        # Open the local file in binary write mode and write the content of the downloaded file
        with open(local_file_path, 'wb') as local_file:
            for chunk in response.iter_content(chunk_size=8192):
                local_file.write(chunk)
        print(f"File downloaded and saved to '{local_file_path}' successfully.")
    else:
        print(f"Failed to download the file. Status code: {response.status_code}")

except Exception as e:
    print(f"Error: {e}")
