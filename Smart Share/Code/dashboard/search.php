<?php 
session_start();
include '../config/database.php';

if (!isset($_SESSION['user_id'])) {
    die("You must be logged in to search for files.");
}

$searchResults = null;

// Predefined tags
$tagsList = [
    "Easy to understand", "Moderate to understand", "Difficult to understand",
    "Handwritten Notes", "Digital Notes", "With Explanation", "With Diagrams"
];

if ($_SERVER["REQUEST_METHOD"] == "POST" && !empty($_POST["search"])) {
    $search = "%" . trim($_POST["search"]) . "%";
    $selectedTags = isset($_POST['tags']) ? $_POST['tags'] : [];

    $query = "SELECT id, filename, tags FROM notes WHERE filename LIKE ?";
    
    // If tags are selected, dynamically append conditions
    $params = [$search];
    if (!empty($selectedTags)) {
        $tagConditions = implode(" OR ", array_fill(0, count($selectedTags), "tags LIKE ?"));
        $query .= " AND ($tagConditions)";
        foreach ($selectedTags as $tag) {
            $params[] = "%$tag%";
        }
    }

    $stmt = $conn->prepare($query);

    // Dynamically bind parameters
    $paramTypes = str_repeat("s", count($params));
    $stmt->bind_param($paramTypes, ...$params);
    $stmt->execute();
    $result = $stmt->get_result(); // Fetch results directly
}
?>

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Search Notes</title>
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
            flex-direction: column;
            margin: 0;
        }
        .search-container {
            background: rgba(255, 255, 255, 0.1);
            padding: 30px;
            border-radius: 15px;
            box-shadow: 0 10px 30px rgba(0, 0, 0, 0.3);
            backdrop-filter: blur(10px);
            text-align: center;
            width: 500px;
        }
        h2 {
            font-size: 24px;
            font-weight: bold;
        }
        .form-control {
            background: rgba(255, 255, 255, 0.2);
            border: none;
            color: white;
        }
        .form-control::placeholder {
            color: rgba(255, 255, 255, 0.7);
        }
        .btn-search {
            background-color: #6a0dad;
            border: none;
            font-size: 16px;
            padding: 10px;
            width: 100%;
            border-radius: 8px;
            color: white;
            transition: transform 0.2s ease, background-color 0.3s;
        }
        .btn-search:hover {
            transform: scale(1.05);
            background-color: #7d1fd6;
        }
        .results {
            margin-top: 20px;
            text-align: left;
        }
        .result-item {
            background: rgba(255, 255, 255, 0.2);
            padding: 10px;
            border-radius: 8px;
            margin-bottom: 10px;
        }
        .result-item a {
            color: #ffffff;
            text-decoration: none;
        }
        .result-item:hover {
            background: rgba(255, 255, 255, 0.3);
        }
        .tags-container {
            text-align: left;
            max-height: 150px;
            overflow-y: auto;
            margin-bottom: 15px;
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
    </style>
</head>
<body>
    <div class="search-container">
        <h2>🔍 Search Notes</h2>
        <form method="POST">
            <div class="mb-3">
                <input type="text" name="search" class="form-control" placeholder="Search by filename" required>
            </div>
            <div class="mb-3 tags-container">
                <label>Filter by Tags:</label><br>
                <?php foreach ($tagsList as $tag) : ?>
                    <input type="checkbox" name="tags[]" value="<?= htmlspecialchars($tag) ?>"> <?= htmlspecialchars($tag) ?><br>
                <?php endforeach; ?>
            </div>
            <button type="submit" class="btn btn-search">Search</button>
        </form>

        <?php if (isset($result)) { ?>
            <div class="results">
                <h4>Search Results:</h4>
                <?php if ($result->num_rows > 0) { ?>
                    <ul class="list-unstyled">
                        <?php while ($row = $result->fetch_assoc()) { ?>
                            <li class="result-item">
                                <a href='download.php?id=<?php echo $row['id']; ?>'>📄 <?php echo htmlspecialchars($row['filename']); ?></a>
                                <br><small class="text-muted">Tags: <?php echo htmlspecialchars($row['tags']); ?></small>
                            </li>
                        <?php } ?>
                    </ul>
                <?php } else { ?>
                    <p class="text-muted">No files found.</p>
                <?php } ?>
            </div>
        <?php } ?>
        <a href="../dashboard.php" class="go-back">⬅ Go Back</a>
    </div>
</body>
</html>
