<?php
include '../config/database.php';

if (isset($_GET["id"])) {
    $id = $_GET["id"];

    $stmt = $conn->prepare("SELECT filename, filetype, filedata FROM notes WHERE id = ?");
    $stmt->bind_param("i", $id);
    $stmt->execute();
    $stmt->store_result();
    $stmt->bind_result($filename, $filetype, $filedata);

    if ($stmt->fetch()) {
        header("Content-Type: " . $filetype);
        header("Content-Disposition: attachment; filename=\"" . basename($filename) . "\"");
        header("Content-Length: " . strlen($filedata));
        echo $filedata;
    } else {
        echo "❌ File not found!";
    }
    $stmt->close();
    $conn->close();
} else {
    echo "❌ Invalid request!";
}
?>
