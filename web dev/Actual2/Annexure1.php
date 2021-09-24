<?php

$conn = mysqli_connect("localhost","root","snores","login");


$sql = "SELECT * FROM upload";
$result = mysqli_query($conn, $sql);
$files = mysqli_fetch_all($result,MYSQLI_ASSOC);

        if(isset($_POST['save']))
{
   
    $filename = $_FILES['myfile']['name'];
    $destination= 'uploads/'.$filename;
    $file  = $_FILES['myfile']['tmp_name'];
    $size = $_FILES['myfile']['size'];
    $mktgrp = $_POST['marketinggroup'];
    $hpvpno = $_POST['hpvpenqno'];
    $cname = $_POST['consultantname'];
    $cenq = $_POST['consultantenqno'];
    $duedate = $_POST['duedate'];
    $phno = $_POST['phno'];
    $description = $_POST['description'];
    $offerref = $_POST['hpvpofferref'];
    $delivery = $_POST['delivery'];
    $remarks = $_POST['remarks'];
    $sql4 = "SELECT * FROM upload WHERE id='$filename'";
    $query_run2 = mysqli_query($conn,$sql4);

        if(move_uploaded_file($file, $destination) && mysqli_num_rows($query_run2)==0)
        {
            $sql2 = "INSERT INTO upload(id,marketinggroup,hpvpenqno,consultantname,consultantenqno,duedate,phno,description,hpvpofferref,delivery,remarks,file)"
                    . " VALUES('$filename','$mktgrp','$hpvpno','$cname','$cenq','$duedate','$phno','$description','$offerref','$delivery','$remarks','$filename')";
             
         
            
            if(mysqli_query($conn,$sql2))
            {
                echo'uploaded';
            }
            else
            {
                echo 'failed to upload';
            }
        
        }
}

if(isset($_GET['file_id']))
{
    $id = $_GET['file_id'];
    $sql3 = "SELECT * FROM upload WHERE id='$id'";
    $result = mysqli_query($conn, $sql3);
    $file3 = mysqli_fetch_assoc($result);
    $filepath = 'uploads/'.$file3['id'];
    
        if(file_exists($filepath))
    {
        
                header('Content-Type: application/octet-stream');
            header('Content-description: File Transfer');
            header('Content-disposition: attachment; filename='.basename($filepath));
            header('Expires:0');
            header('Cache-Control: must-revalidate');
            header('Pragma: public');
            header('Content-Length:'.filesize('uploads/'.$file3['id']));
            readfile('uploads'.$file3['id']);

    }

}  

?>


<!DOCTYPE html>
<html>
<head>
    <title>Annexure 1</title>
    <link href="Top.css" rel="stylesheet" type="text/css"  />
    <link href="Login.css" rel="stylesheet" type="text/css"  />
    <link href="Default.css" rel="stylesheet" type="text/css"  />
    <link href="buttons.css" rel="stylesheet" type="text/css"  />
    
</head>
</head>
<body>
    <header class="headers">
    <div >
    <img src="icon1.jpg" class="icon1" alt="Icon 1" />
    <img src="icon2.jpeg" class="icon2" alt="Icon 2" />
    <h1 class="head1">POWER SECTOR-MARKETING</h1>
    <br>
    <form action="Page1.php">
        <button class="button3 button2e">Back to Page 1</button></form><br><br>
    <button class="button1">HOME</button>
    <button class="button1">ABOUT US</button>
    <button class="button1">OUR CUSTOMERS</button>
    <button class="button1">BUSINESS ENVIRONMENT</button>
    <button class="button1">ONLINE SYSTEM</button>
    <button class="button1">TENDERS</button>
    <button class="button1">CONTRACTS</button>
    <button class="button1">EMPLOYEE CORNER</button>
    


</div>
</header>
<div class="row">
    
        
        <table>
            <tr class="ct">
                <th >Current Tenders</th>
            </tr>
        </table>
    
    
        <table>
            <tr class="at">
                <th></th>
                <th>All Tenders</th>
                <th></th>
            </tr>
        </table>
    
        <table id="Annex1">
          
   
           <thead class="tr1 tr1b">
            
            <th>Marketing Group</th>
            <th>HPVPENQ.NO</th>
            <th>Consultant/Customer name</th>
            <th>Consultant/CustomerEnq</th>
            <th>DueDate</th>
            <th>PhNo</th>
            <th>Description</th>
            <th>HPVP OfferRef</th>
            <th>Delivery</th>
            <th>Remarks</th>
            <th>Upload</th>
            <th>Actions</th>
            <th>Delete</th>            
            </thead>
        <tbody class="tr1">           
            <?php foreach($files as $file): 
                $sno=$file['sno'] ?>
            <tr class="row">
                
                <td>
                    <div contentEditable='true' class='edit' id='marketinggroup_<?php echo $sno; ?>'>
                    <?php echo $file['marketinggroup'];?></div></td>
                <td>
                    <div contentEditable='true' class='edit' id='hpvpenqno_<?php echo $sno; ?>'>
                    <?php echo $file['hpvpenqno'];?></div></td>
                <td>
                    <div contentEditable='true' class='edit' id='consultantname_<?php echo $sno; ?>'>
                    <?php echo $file['consultantname'];?></div></td>
                <td>
                    <div contentEditable='true' class='edit' id='consultantenqno_<?php echo $sno; ?>'>
                    <?php echo $file['consultantenqno'];?></div></td>
                <td>
                    <div contentEditable='true' class='edit' id='duedate_<?php echo $sno; ?>'>
                    <?php echo $file['duedate'];?></td>
                <td>
                    <div contentEditable='true' class='edit' id='phno_<?php echo $sno; ?>'>
                    <?php echo $file['phno'];?></div></td>
                <td>
                    <div contentEditable='true' class='edit' id='description_<?php echo $sno; ?>'>
                    <?php echo $file['description'];?></div></td>
                <td>
                    <div contentEditable='true' class='edit' id='hpvpofferref_<?php echo $sno; ?>'>
                    <?php echo $file['hpvpofferref'];?></div></td>
                <td>
                    <div contentEditable='true' class='edit' id='delivery_<?php echo $sno; ?>'>
                    <?php echo $file['delivery'];?></div></td>
                <td>
                    <div contentEditable='true' class='edit' id='remarks_<?php echo $sno; ?>'>
                    <?php echo $file['remarks'];?></div></td>  
                <td>
                    
                    <a class="a4"href="uploadfileonly.php?file_id=<?php echo $file['hpvpenqno'];?>">Upload</a>  
                </td>             
                <td>
                    <a class="a3" href="Annexure1.php?file_id=<?php echo $file['id'];?>">Download</a>                   
                </td>
                
                <td><a href="javascript:void(0);" class="delete a2" data-id="<?php echo $file['hpvpenqno']; ?>">Delete</a>
                </td>
                
            </tr>           
            <?php endforeach ; ?>
            
        </tbody>
       </table>
       
       <script type="text/javascript" src="https://ajax.googleapis.com/ajax/libs/jquery/3.3.1/jquery.min.js?ver=3.3.1">
       </script>
       <script type="text/javascript">
(function($) {
    $(document).on('click', '.row a.delete', function() {
        var _id = $(this).attr('data-id');
        var _row = $(this).parent().parent();
        $.ajax({
            url: 'delete.php',
            data: {
                hpvpenqno: _id
            },
            type: 'POST',
            dataType: 'json',
            success: function(__resp) {
                if (__resp.success) {
                    _row.remove(); // Deletes the row from the table
                }
            }
        });
    });
})(jQuery);
</script>
       
<script>
$(document).ready(function(){
 
 // Add Class
 $('.edit').click(function(){
  $(this).addClass('editMode');
 });

 // Save data
 $(".edit").focusout(function(){
  $(this).removeClass("editMode");
  var id = this.id;
  var split_id = id.split("_");
  var field_name = split_id[0];
  var edit_id = split_id[1];
  var value = $(this).text();

  $.ajax({
   url: 'update2.php',
   type: 'post',
   data: { field:field_name, value:value, id:edit_id },
   success:function(response){
    console.log('Save successfully'); 
   }
  });
 
 });

});
</script>


       <form action="upload.php" >
        <button name="Add" class="button2 button2a">Add</button>
       </form>
      
       



    </div>
</div>
</body>
</html>
