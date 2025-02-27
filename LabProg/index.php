<?php
    // Display a welcome message
    echo "<h1>PHP is Working! 🎉</h1>";
    
    // Get the current date and time
    echo "<p>Today is " . date("l, F j, Y") . "</p>";
    echo "<p>Current time: " . date("h:i:s A") . "</p>";

    // Display server information
    echo "<h3>Server Info:</h3>";
    echo "<pre>";
    print_r($_SERVER);
    echo "</pre>";
?>
