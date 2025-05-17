<?php
session_start();
include '../config/database.php';

if (!isset($_SESSION['user_id'])) {
    header("Location: ../auth/login.php");
    exit();
}

$user_id = $_SESSION['user_id'];

if ($_SERVER["REQUEST_METHOD"] == "POST") {
    $full_name = $_POST['full_name'];
    $bio = $_POST['bio'];

    $profile_picture = null;
    if (!empty($_FILES['profile_picture']['name'])) {
        $profile_picture = time() . '_' . $_FILES['profile_picture']['name'];
        move_uploaded_file($_FILES['profile_picture']['tmp_name'], "../assets/uploads/" . $profile_picture);
    }

    if ($profile_picture) {
        $stmt = $conn->prepare("UPDATE users SET full_name = ?, bio = ?, profile_picture = ? WHERE id = ?");
        $stmt->bind_param("sssi", $full_name, $bio, $profile_picture, $user_id);
    } else {
        $stmt = $conn->prepare("UPDATE users SET full_name = ?, bio = ? WHERE id = ?");
        $stmt->bind_param("ssi", $full_name, $bio, $user_id);
    }

    if ($stmt->execute()) {
        header("Location: profile.php");
        exit();
    }
}

$stmt = $conn->prepare("SELECT full_name, bio FROM users WHERE id = ?");
$stmt->bind_param("i", $user_id);
$stmt->execute();
$stmt->bind_result($full_name, $bio);
$stmt->fetch();
$stmt->close();
?>

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Edit Profile</title>
    <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.3.0/dist/css/bootstrap.min.css" rel="stylesheet">
</head>
<body class="bg-dark text-light">
    <div class="container mt-5">
        <div class="card bg-secondary p-4">
            <h2 class="text-center">Edit Profile</h2>
            <form method="POST" enctype="multipart/form-data">
                <div class="mb-3">
                    <label class="form-label">Full Name</label>
                    <input type="text" name="full_name" class="form-control" value="<?php echo htmlspecialchars($full_name); ?>" required>
                </div>
                <div class="mb-3">
                    <label class="form-label">Bio</label>
                    <textarea name="bio" class="form-control" rows="3"><?php echo htmlspecialchars($bio); ?></textarea>
                </div>
                <div class="mb-3">
                    <label class="form-label">Profile Picture</label>
                    <input type="file" name="profile_picture" class="form-control">
                </div>
                <button type="submit" class="btn btn-success">Save Changes</button>
                <a href="profile.php" class="btn btn-secondary">Cancel</a>
            </form>
        </div>
    </div>
</body>
</html>
