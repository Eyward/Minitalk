# Minitalk
The purpose of this project is to code a small data exchange program using UNIX signals:

• The server must be started first. After its launch, it has to print its PID.
• The client takes two parameters:
    ◦ The server PID.
    ◦ The string to send.
• The client must send the string passed as a parameter to the server.
Once the string has been received, the server must print it.
• The server has to display the string pretty quickly.
• The server should be able to receive strings from several clients in a row without
needing to restart.
• The communication between your client and your server has to be done only using
UNIX signals.
