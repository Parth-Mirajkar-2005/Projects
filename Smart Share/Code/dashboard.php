<?php
session_start();
include 'config/database.php';

if (!isset($_SESSION['user_id'])) {
    header("Location: auth/login.php");
    exit();
}

$user_id = $_SESSION['user_id'];
$stmt = $conn->prepare("SELECT full_name FROM users WHERE id = ?");
$stmt->bind_param("i", $user_id);
$stmt->execute();
$stmt->bind_result($full_name);
$stmt->fetch();
$stmt->close();
?>

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Dashboard - Notes App</title>
    <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.3.0/dist/css/bootstrap.min.css" rel="stylesheet">
    <script src="https://cdnjs.cloudflare.com/ajax/libs/jquery/3.6.0/jquery.min.js"></script>
    <script src="https://cdnjs.cloudflare.com/ajax/libs/bootstrap/5.3.0/js/bootstrap.bundle.min.js"></script>
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
        .dashboard-container {
            background: rgba(255, 255, 255, 0.15);
            backdrop-filter: blur(10px);
            padding: 40px;
            border-radius: 16px;
            box-shadow: 0px 6px 15px rgba(0, 0, 0, 0.4);
            width: 90%;
            max-width: 800px;
            text-align: center;
            animation: fadeIn 1s ease-in-out;
        }
        @keyframes fadeIn {
            from { opacity: 0; transform: translateY(-20px); }
            to { opacity: 1; transform: translateY(0); }
        }
        .btn-custom {
            background: #6a11cb;
            border: none;
            transition: 0.3s;
            padding: 12px;
            font-size: 18px;
            width: 100%;
            border-radius: 8px;
            margin: 10px 0;
        }
        .btn-custom:hover {
            background: #2575fc;
            transform: scale(1.05);
        }
        .navbar {
            background: rgba(0, 0, 0, 0.8);
            padding: 15px;
            border-radius: 12px;
            width: 90%;
            max-width: 800px;
            position: absolute;
            top: 20px;
            display: flex;
            justify-content: space-between;
            align-items: center;
        }
        .navbar-text {
            font-size: 18px;
        }
        .profile-btn {
            background: transparent;
            border: none;
            color: white;
            font-size: 18px;
            cursor: pointer;
            text-decoration: underline;
        }
        .profile-btn:hover {
            color: #6a11cb;
        }
    </style>
</head>
<body>
    <nav class="navbar navbar-dark">
        <a class="navbar-brand text-light">📖 Notes App</a>
        <span class="navbar-text">Welcome, <strong>
            <a href="pages/profile.php" class="profile-btn"><?php echo htmlspecialchars($full_name ?: "User"); ?></a>
        </strong>!</span>
        <a href="auth/logout.php" class="btn btn-danger">Logout</a>
    </nav>
    
    <div class="dashboard-container">
        <h1 class="mb-4">📌 Wisdom Panel</h1>
        <div class="row">
            <div class="col-md-6">
                <a href="dashboard/upload.php" class="btn btn-custom">📂 Upload Notes</a>
            </div>
            <div class="col-md-6">
                <a href="dashboard/search.php" class="btn btn-custom">🔍 Search Notes</a>
            </div>
        </div>
        <div class="row mt-3">
            <div class="col-12 d-flex justify-content-center">
                <a href="dashboard/my_notes.php" class="btn btn-custom">📄 My Notes</a>
            </div>
        </div>
    </div>
</body>
</html>
