<?php
if ($_SERVER["REQUEST_METHOD"] == "POST") {
    include '../config/database.php';

    $full_name = trim($_POST['full_name']);
    $email = trim($_POST['email']);
    $username = trim($_POST['username']);
    $password = trim($_POST['password']);

    if (empty($full_name) || empty($email) || empty($username) || empty($password)) {
        $error = "All fields are required.";
    } elseif (!filter_var($email, FILTER_VALIDATE_EMAIL)) {
        $error = "Invalid email format.";
    } else {
        // Check if email already exists
        $check_email = $conn->prepare("SELECT id FROM users WHERE email = ?");
        $check_email->bind_param("s", $email);
        $check_email->execute();
        $check_email->store_result();

        if ($check_email->num_rows > 0) {
            $error = "Email already registered. Try another.";
        } else {
            // Hash password
            $hashed_password = password_hash($password, PASSWORD_DEFAULT);

            // Prepare SQL statement
            $stmt = $conn->prepare("INSERT INTO users (full_name, email, username, password) VALUES (?, ?, ?, ?)");
            $stmt->bind_param("ssss", $full_name, $email, $username, $hashed_password);

            if ($stmt->execute()) {
                header("Location: login.php?success=registered");
                exit();
            } else {
                $error = "Registration failed: " . $stmt->error;
            }
        }
        $check_email->close();
        $stmt->close();
    }
}
?>

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Register</title>
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
        .register-container {
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
        .register-btn {
            background: #6a11cb;
            border: none;
            transition: 0.3s;
        }
        .register-btn:hover {
            background: #2575fc;
            transform: scale(1.05);
        }
        .form-control {
            background: rgba(255, 255, 255, 0.2);
            color: white;
            border: 1px solid white;
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
    <div class="register-container">
        <h2 class="mb-4">📝 Register</h2>
        <?php if (isset($error)) echo "<div class='alert'>$error</div>"; ?>
        <form method="POST">
            <div class="mb-3">
                <input type="text" name="full_name" class="form-control" placeholder="Full Name" required>
            </div>
            <div class="mb-3">
                <input type="email" name="email" class="form-control" placeholder="Email" required>
            </div>
            <div class="mb-3">
                <input type="text" name="username" class="form-control" placeholder="Username" required>
            </div>
            <div class="mb-3">
                <input type="password" name="password" class="form-control" placeholder="Password" required>
            </div>
            <button type="submit" class="btn register-btn w-100">Register</button>
        </form>
        <p class="mt-3">Already have an account? <a href="login.php" style="color:#ffcc70;">Login</a></p>
    </div>
</body>
</html>
