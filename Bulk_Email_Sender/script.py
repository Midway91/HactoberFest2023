import pandas as pd
import smtplib
from email.mime.text import MIMEText
from email.mime.multipart import MIMEMultipart
from email.mime.application import MIMEApplication

# Read Excel data
df = pd.read_excel('hzshashwat.xlsx')

# Email configuration
smtp_server = 'smtp.example.com'
smtp_port = 587  # Change to your SMTP port
smtp_username = 'your_email'
smtp_password = 'your_password'
sender_email = 'your_email'
subject = 'Congratulations!'

# Read the email template
with open('template/index.html', 'r') as template_file:
    email_template = template_file.read()

# Initialize SMTP server
server = smtplib.SMTP(smtp_server, smtp_port)
server.starttls()
server.login(smtp_username, smtp_password)

# Loop through recipients and send emails
for index, row in df.iterrows():
    recipient_email = row['Email']
    recipient_name = row['Name']

    # Create email message
    message = MIMEMultipart()
    message['From'] = sender_email
    message['To'] = recipient_email
    message['Subject'] = subject

    # Inject recipient-specific data into the email template
    email_content = email_template.replace('{name}', recipient_name)

    # Attach HTML content to the email
    message.attach(MIMEText(email_content, 'html'))

    # Send email
    server.sendmail(sender_email, recipient_email, message.as_string())

    print(f"Email sent to {recipient_name} at {recipient_email}")

# Quit the SMTP server
server.quit()
