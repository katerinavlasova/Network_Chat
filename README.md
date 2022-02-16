# Network Chat

Client-server app on Qt with C++.

## Description

This is a client-server app. First of all, a user needs to log in. If the user puts the wrong username-password, a warning will drop.
After logging in, the user can send messages from client to server and vice versa.

Messages are sent one after another and displayed successively.


## About the project
TCP was used.

### GUI
The account login screen has a button "Login" and two fields: for a username and a password. QMessageBox is dropped if the entered data is wrong.
A chat has a field for a chat history, a field for new messages and a button "send". The message field is cleared but the message is added to the chat history.


### Client and server sides

After the user is logged in, the login screen is hidden and the chat window is displayed. After the user enters a message, it's converted to QByteArray and sent to another side.
When the client/server receives a new message, it's converted to QString again and then displayed in the chat history.

## Example

Here are examples of how the program works.

Gif example:

<img src="https://github.com/katerinavlasova/Network_Chat/blob/master/media/chat_example.gif">


Screenshots

Start of the program

<img src="https://github.com/katerinavlasova/Network_Chat/blob/master/media/loginForm.png" width="600" height= "250">

After logging in, enter a message from the server:

<img src="https://github.com/katerinavlasova/Network_Chat/blob/master/media/enterMessageFromServer.png" width="600" height= "250">

Send the message from the server:

<img src="https://github.com/katerinavlasova/Network_Chat/blob/master/media/receiveMessageFromServer.png" width="600" height= "250">

Enter a message from the client:

<img src="https://github.com/katerinavlasova/Network_Chat/blob/master/media/enterMessageFromClient.png" width="600" height= "250">

Receive the message from the client:

<img src="https://github.com/katerinavlasova/Network_Chat/blob/master/media/receiveMessageFromClient.png" width="600" height= "250">

