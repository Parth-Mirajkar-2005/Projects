<?php
session_start();
include '../config/database.php';

if (!isset($_SESSION['user_id'])) {
    header("Location: ../auth/login.php");
    exit();
}

$user_id = $_SESSION['user_id'];
$stmt = $conn->prepare("SELECT id, filename FROM notes WHERE user_id = ?");
$stmt->bind_param("i", $user_id);
$stmt->execute();
$result = $stmt->get_result(); // Fetch all results properly

?>

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>My Notes</title>
    <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.3.0/dist/css/bootstrap.min.css" rel="stylesheet">
    <style>
        body {
            background: linear-gradient(135deg, #1f1c2c, #928DAB);
            color: white;
            font-family: 'Poppins', sans-serif;
            height: 100vh;
            display: flex;
            justify-content: center;
            align-items: center;
            flex-direction: column;
        }
        .container {
            background: rgba(255, 255, 255, 0.15);
            backdrop-filter: blur(10px);
            padding: 30px;
            border-radius: 12px;
            box-shadow: 0px 4px 10px rgba(0, 0, 0, 0.3);
            width: 90%;
            max-width: 600px;
            text-align: center;
        }
        .btn-custom {
            background: #6a11cb;
            border: none;
            transition: 0.3s;
            padding: 12px;
            font-size: 16px;
            border-radius: 8px;
            margin: 5px;
            width: 100%;
        }
        .btn-custom:hover {
            background: #2575fc;
            transform: scale(1.05);
        }
    </style>
</head>
<body>
    <h2>📄 My Uploaded Notes</h2>
    <div class="container">
        <?php if ($result->num_rows > 0) { ?>
            <ul class="list-group">
                <?php while ($row = $result->fetch_assoc()) { ?>
                    <li class="list-group-item">
                        <a href='../dashboard/download.php?id=<?php echo $row['id']; ?>'>
                            <?php echo htmlspecialchars($row['filename']); ?>
                        </a>
                    </li>
                <?php } ?>
            </ul>
        <?php } else { ?>
            <p class="text-muted">No notes uploaded yet.</p>
        <?php } ?>
    </div>
    <a href="../dashboard.php" class="btn btn-custom mt-3">Go Back</a>
</body>
</html>
