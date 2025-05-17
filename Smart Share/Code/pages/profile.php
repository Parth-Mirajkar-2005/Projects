<?php
session_start();
include '../config/database.php';

if (!isset($_SESSION['user_id'])) {
    header("Location: ../auth/login.php");
    exit();
}

$user_id = $_SESSION['user_id'];
$stmt = $conn->prepare("SELECT full_name, bio, profile_picture FROM users WHERE id = ?");
$stmt->bind_param("i", $user_id);
$stmt->execute();
$stmt->bind_result($full_name, $bio, $profile_picture);
$stmt->fetch();
$stmt->close();
?>

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>My Profile</title>
    <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.3.0/dist/css/bootstrap.min.css" rel="stylesheet">
</head>
<body class="bg-dark text-light">
    <div class="container mt-5">
        <div class="card bg-secondary p-4">
            <h2 class="text-center">My Profile</h2>
            <div class="text-center">
                <img src="../assets/uploads/<?php echo $profile_picture ?: 'default.png'; ?>" alt="Profile Picture" class="rounded-circle" width="150">
            </div>
            <p class="text-center mt-3"><strong>Name:</strong> <?php echo htmlspecialchars($full_name ?: 'N/A'); ?></p>
            <p class="text-center"><strong>Bio:</strong> <?php echo htmlspecialchars($bio ?: 'No bio available.'); ?></p>
            <div class="text-center">
                <a href="edit_profile.php" class="btn btn-primary">Edit Profile</a>
                <a href="../dashboard.php" class="btn btn-secondary">Back</a>
            </div>
        </div>
    </div>
</body>
</html>
