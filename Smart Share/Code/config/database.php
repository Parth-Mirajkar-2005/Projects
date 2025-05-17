<?php
$servername = "localhost";  // XAMPP runs MySQL on localhost
$username = "root";         // Default XAMPP user is "root"
$password = "";             // No password by default
$database = "notes_app";    // Our database name

// Create connection
$conn = new mysqli($servername, $username, $password, $database);

// Check connection
if ($conn->connect_error) {
    die("Connection failed: " . $conn->connect_error);
}
?>
