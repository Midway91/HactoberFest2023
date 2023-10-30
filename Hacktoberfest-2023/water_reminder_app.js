//Creating a simple water reminder app in JavaScript involves setting up a basic web page
//with a timer and notifications. Here's a basic example using HTML, CSS, and JavaScript to create a water reminder app

<!DOCTYPE html>
<html>
<head>
    <title>Water Reminder App</title>
    <style>
        body {
            font-family: Arial, sans-serif;
            text-align: center;
        }

        #reminder {
            font-size: 24px;
        }
    </style>
</head>
<body>
    <h1>Water Reminder App</h1>
    <p id="reminder">It's time to drink water!</p>
    
    <script>
        const reminder = document.getElementById('reminder');

        function showNotification() {
            if (Notification.permission === 'granted') {
                const notification = new Notification('Drink Water', {
                    body: 'Stay hydrated for your health!',
                });
            }
        }

        function setReminder() {
            const now = new Date();
            const hours = now.getHours();
            const minutes = now.getMinutes();

            // Set the reminder time (e.g., every 30 minutes)
            const reminderHour = hours;
            const reminderMinute = minutes + 30;

            if (reminderMinute >= 60) {
                reminderHour += 1;
                reminderMinute -= 60;
            }

            reminder.textContent = `Next reminder at ${reminderHour}:${reminderMinute}`;

            setTimeout(showNotification, (reminderHour - hours) * 3600000 + (reminderMinute - minutes) * 60000);
        }

        // Check if the browser supports notifications
        if ('Notification' in window) {
            Notification.requestPermission()
                .then(function(permission) {
                    if (permission === 'granted') {
                        setReminder();
                    }
                });
        }

        // Update the reminder every 30 minutes
        setInterval(setReminder, 1800000); // 30 minutes in milliseconds
    </script>
</body>
</html>
