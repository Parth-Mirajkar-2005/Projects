<?php
session_start();
include '../config/database.php';

if ($_SERVER["REQUEST_METHOD"] == "POST") {
    $username = trim($_POST['username']);
    $password = $_POST['password'];

    $stmt = $conn->prepare("SELECT id, password FROM users WHERE username = ?");
    $stmt->bind_param("s", $username);
    $stmt->execute();
    $stmt->store_result();
    $stmt->bind_result($id, $hashed_password);
    $stmt->fetch();

    if ($stmt->num_rows > 0 && password_verify($password, $hashed_password)) {
        $_SESSION['user_id'] = $id;
        $_SESSION['username'] = $username;
        header("Location: ../dashboard.php");
        exit();
    } else {
        $error = "Invalid username or password.";
    }
}
?>

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Login</title>
    <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.3.0/dist/css/bootstrap.min.css" rel="stylesheet">
    <style>
        body {
            background: linear-gradient(135deg, #1f1c2c, #928DAB);
            height: 100vh;
            display: flex;
            justify-content: center;
            align-items: center;
            font-family: 'Poppins', sans-serif;
        }
        .auth-container {
            background: rgba(255, 255, 255, 0.15);
            backdrop-filter: blur(10px);
            padding: 30px;
            border-radius: 12px;
            box-shadow: 0px 4px 10px rgba(0, 0, 0, 0.3);
            width: 100%;
            max-width: 400px;
            text-align: center;
            animation: fadeIn 1s ease-in-out;
        }
        @keyframes fadeIn {
            from { opacity: 0; transform: translateY(-20px); }
            to { opacity: 1; transform: translateY(0); }
        }
        .auth-btn {
            background: #6a11cb;
            border: none;
            transition: 0.3s;
        }
        .auth-btn:hover {
            background: #2575fc;
            transform: scale(1.05);
        }
        .form-control {
            background: rgba(255, 255, 255, 0.2);
            color: white;
            border: 1px solid white;
        }
        .form-control::placeholder {
            color: rgba(255, 255, 255, 0.7);
        }
        .form-control:focus {
            border-color: #6a11cb;
            box-shadow: 0px 0px 8px rgba(106, 17, 203, 0.5);
            background: rgba(255, 255, 255, 0.3);
        }
        .alert {
            background: rgba(255, 0, 0, 0.7);
            color: white;
            padding: 10px;
            border-radius: 8px;
        }
    </style>
</head>
<body>
    <div class="auth-container">
        <h2 class="mb-4">🔐 Login</h2>
        <?php if (isset($error)) echo "<div class='alert'>$error</div>"; ?>
        <form method="POST">
            <div class="mb-3">
                <input type="text" name="username" class="form-control" placeholder="Username" required>
            </div>
            <div class="mb-3">
                <input type="password" name="password" class="form-control" placeholder="Password" required>
            </div>
            <button type="submit" class="btn auth-btn w-100">Login</button>
        </form>
        <p class="mt-3">Don't have an account? <a href="register.php" style="color:#ffcc70;">Register</a></p>
    </div>
</body>
</html>