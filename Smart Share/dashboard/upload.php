<?php
session_start();
include '../config/database.php';

if (!isset($_SESSION['user_id'])) {
    header("Location: ../auth/login.php");
    exit();
}

$message = ""; 

// Predefined tags
$tagsList = [
    "Easy to understand", "Moderate to understand", "Difficult to understand",
    "Handwritten Notes", "Digital Notes", "With Explanation", "With Diagrams"
];

if ($_SERVER["REQUEST_METHOD"] == "POST") {
    if (isset($_FILES["file"]) && $_FILES["file"]["error"] == 0 && isset($_POST['tags'])) {
        $filename = $_FILES["file"]["name"];
        $filetype = $_FILES["file"]["type"];
        $filesize = $_FILES["file"]["size"];
        $filedata = file_get_contents($_FILES["file"]["tmp_name"]);
        $userid = $_SESSION["user_id"];

        // Get selected tags as a comma-separated string
        $tags = implode(", ", $_POST['tags']);

        if ($filesize > 5 * 1024 * 1024) {
            $message = "<div class='alert alert-warning'>⚠ File size exceeds 5MB limit.</div>";
        } else {
            $sql = "INSERT INTO notes (user_id, filename, filetype, filesize, filedata, tags) VALUES (?, ?, ?, ?, ?, ?)";
            $stmt = $conn->prepare($sql);
            $stmt->bind_param("ississ", $userid, $filename, $filetype, $filesize, $filedata, $tags);

            if ($stmt->execute()) {
                $message = "<div class='alert alert-success'>✅ File uploaded successfully with tags!</div>";
            } else {
                $message = "<div class='alert alert-danger'>❌ Error: " . $conn->error . "</div>";
            }
            $stmt->close();
        }
    } else {
        $message = "<div class='alert alert-danger'>❌ No file uploaded, no tags selected, or an error occurred.</div>";
    }
}
?>

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Upload Notes</title>
    <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.3.0/dist/css/bootstrap.min.css" rel="stylesheet">
    <style>
        body {
            background: linear-gradient(135deg, #2c2c38, #1f1f2e);
            color: white;
            font-family: 'Poppins', sans-serif;
            height: 100vh;
            display: flex;
            justify-content: center;
            align-items: center;
            margin: 0;
        }
        .upload-container {
            background: rgba(255, 255, 255, 0.1);
            padding: 30px;
            border-radius: 15px;
            box-shadow: 0 10px 30px rgba(0, 0, 0, 0.3);
            backdrop-filter: blur(10px);
            text-align: center;
            width: 400px;
        }
        h2 {
            font-size: 24px;
            font-weight: bold;
        }
        .btn-upload {
            background-color: #6a0dad;
            border: none;
            font-size: 16px;
            padding: 10px;
            width: 100%;
            border-radius: 8px;
            color: white;
            transition: transform 0.2s ease, background-color 0.3s;
        }
        .btn-upload:hover {
            transform: scale(1.05);
            background-color: #7d1fd6;
        }
        .go-back {
            margin-top: 10px;
            color: white;
            text-decoration: none;
            display: inline-block;
        }
        .go-back:hover {
            text-decoration: underline;
        }
        .tags-container {
            text-align: left;
            max-height: 150px;
            overflow-y: auto;
        }
    </style>
</head>
<body>
    <div class="upload-container">
        <h2>📂 Upload Notes</h2>
        <?= $message ?> 
        <form method="POST" enctype="multipart/form-data">
            <div class="mb-3">
                <input type="file" name="file" class="form-control" required>
            </div>
            <div class="mb-3 tags-container">
                <label>Select Tags:</label><br>
                <?php foreach ($tagsList as $tag) : ?>
                    <input type="checkbox" name="tags[]" value="<?= htmlspecialchars($tag) ?>"> <?= htmlspecialchars($tag) ?><br>
                <?php endforeach; ?>
            </div>
            <button type="submit" class="btn btn-upload">Upload</button>
        </form>
        <a href="../dashboard.php" class="go-back">⬅ Go Back</a>
    </div>
</body>
</html>
