from gtts import gTTS

# Text to be converted to speech
text = "Hello, this is a text-to-speech example in Python."

# Language in which you want to convert
language = "en"

# Create a gTTS object
tts = gTTS(text=text, lang=language, slow=False)

# Save the converted audio to a file
tts.save("output.mp3")

# Play the audio (optional)
import os
os.system("mpg321 output.mp3")  # You can use any audio player command that works on your system
