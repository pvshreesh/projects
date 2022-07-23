<?php
    session_start();
?>

<html>

<head>

	<title> View</title>

    <style type="text/css">

	
	#butn {
		position:absolute;
		top:100px;
		left:1700px;
		font-size:15px;
	}
	#butn2 {
		position:absolute;
		top:500px;
		left:550px;
	}
	#t {
		position:absolute;
		top:100px;
		left:100px;
	}
	#no {
		position:absolute;
		top:100px;
		left:100px;
		font-size:30px;
	}
	
	</style>
    
</head>

<body> 
	<form method="post">
		<div id="butn"><button type="submit" value="logout" id="logout" name="logout" > Logout </button> </div>
		<div id="butn2"><button type="submit" value="back" id="back" name="back" > back </button> </div>
    </form>   
    

	<?php
		if(!isset($_SESSION['uid'])){
			header('location:login.php');
		}
		if(isset($_POST['logout'])){
            session_unset();
            session_destroy();
            header('location:login.php');

        }
		if(isset($_POST['back'])){
            header('location:home.php');
            
        }

        $servername='localhost';
     	$user='root';
    	$pwd='';
     	$db='user';
     	$conn = mysqli_connect($servername, $user, $pwd,$db);
     	if (!$conn) {
     		die("Connection failed: " . mysqli_connect_error());
     	}

		$uname=$_SESSION["uname"];
		$uid=$_SESSION["uid"];
		$mno=$_SESSION["mno"];
        
        $sql = "SELECT uid, address, mail, last_update from personal_data";
        $result = $conn->query($sql);
	?>
	<div>
	<?php
		
        if ($result->num_rows > 0) {
			echo "<table border='1' id='t'>";
			echo "<tr><td> uid </td><td> address </td><td> mail </td><td> last_update </td><td> Delete </td></tr>";
    
            while($row = $result->fetch_assoc()) {
				?>

			<tr>
            	<td><?php 
				echo $row["uid"]; ?></td>
                <td><?php echo $row["address"]; ?></td>
                <td><?php echo $row['mail']; ?></td>
                <td><?php echo $row['last_update']; ?></td>
                <td>
    				<form action="<?php $a=null;$a=$row['uid']; ?>" method="post">
					<?php echo'<input type="hidden" name ="id" value=' .$row["uid"].'>' ?>
        			<button type="submit" value="submit" id="a" name="submit" > Delete </button>
        			
    			</form></td>
            </tr>
			<?php
				if(isset($_POST['submit'])){


					
					
					$servername='localhost';
					$user='root';
					$pwd='';
					$db='user';
						
					$conn = mysqli_connect($servername, $user, $pwd,$db);
			
					$newdel=$_REQUEST['id'];
					echo $newdel;
					if (!$conn) {
						die("Connection failed: " . mysqli_connect_error());
					}
					$query="DELETE from personal_data where uid='$newdel'";
					$result=mysqli_query($conn,$query);
					mysqli_query($conn,$query);
					echo "User edited";
					header('location:view.php');
				}
            }
			echo "</table>";
        } else {
            echo "<div id='no'>NO results</div>";
        }

    ?>
	</div>
	
</body>
</html>

