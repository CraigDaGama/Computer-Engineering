<?php 

    $username = $_POST["un"];
    echo "<br>First name is " . $username;
    
    $email = $_POST["pm"]; 
    echo "<br>Email Address is " . $email;

    $gender = $_POST["gender"];
    echo "<br>Gender selected is " . $gender;


    $experience = $_POST["interests"];
    $exp = "";
    
    foreach($experience as $value) {
        $exp .= $value . " ";  
    }
    
    $expString = implode(", ", $experience);
    
    echo "<br>Experience selected is " . $exp;

    $country = $_POST["country"];
    echo "<br>Country selected is " . $country;

    
    $dob = $_POST["birthdate"];
    echo "<br>Date of birth is " . $dob;


    $biodata = $_POST["bio"];
    echo "<br>First name is " . $biodata;


    $theme = $_POST["theme"];
    echo "<br>The selected theme color is: " . $theme;

   
    $phone = $_POST["phno"];
    echo "<br>Phone Number is" . $phone;

    $social = $_POST["website"];

    echo "<br>Social accounts" . $social;
    

    $conn = mysqli_connect("localhost", "root", "", "webTech");
    
    
    if($conn) {
        echo "<br>Connection is successful";
    } else {
        echo "Connection failed";
        exit();
    }
    
    $q1= "INSERT INTO player (user_name, email, gender, experience, Country, dob, biodata, Theme, Phone_no, Social) values ('$username', '$email', '$gender', '$expString', '$country', '$dob', '$biodata', '$theme', '$phone', '$social')";
    $r1= mysqli_query($conn, $q1);
    
    if($r1)
    {
        echo "<br>data inserted successfully";
    }
    else{
        echo "data insertion failed";
    }


    
     $selectQuery = "SELECT * FROM player";
     $result = mysqli_query($conn, $selectQuery);
 
     if (mysqli_num_rows($result) > 0) {
         echo "<h3>Players List:</h3>";
         echo "<table border='1'><tr><th>Username</th><th>Email</th><th>Gender</th><th>Experience</th><th>Country</th><th>DOB</th><th>Biodata</th><th>Theme</th><th>Phone No</th><th>Social</th></tr>";
         while ($row = mysqli_fetch_assoc($result)) {
             echo "<tr><td>{$row['user_name']}</td><td>{$row['email']}</td><td>{$row['gender']}</td><td>{$row['experience']}</td><td>{$row['Country']}</td><td>{$row['dob']}</td><td>{$row['biodata']}</td><td>{$row['Theme']}</td><td>{$row['Phone_no']}</td><td>{$row['Social']}</td></tr>";
         }
         echo "</table>";
     } else {
         echo "No data found.";
     }
    
    
    mysqli_close($conn);

?>
