<?php

$conn = mysqli_connect("localhost","root","snores","login");


$sql = "SELECT * FROM annex";
$result = mysqli_query($conn, $sql);
$files = mysqli_fetch_all($result,MYSQLI_ASSOC);



if(isset($_GET['file_id']))
{
    $id = $_GET['file_id'];
    $sql3 = "SELECT * FROM annex WHERE id='$id'";
    $result = mysqli_query($conn, $sql3);
    $file3 = mysqli_fetch_assoc($result);
    $filepath = 'annexure/'.$file3['id'];
    
        if(file_exists($filepath))
    {
        
                header('Content-Type: application/octet-stream');
            header('Content-description: File Transfer');
            header('Content-disposition: attachment; filename='.basename($filepath));
            header('Expires:0');
            header('Cache-Control: must-revalidate');
            header('Pragma: public');
            header('Content-Length:'.filesize('annexure/'.$file3['id']));
            readfile('annexure'.$file3['id']);

    }

}  

?>
<!DOCTYPE html>
<!--
To change this license header, choose License Headers in Project Properties.
To change this template file, choose Tools | Templates
and open the template in the editor.
-->
<html>
    <head>
        <meta charset="UTF-8">
        <title>Annexure 2</title>
    <link href="Top.css" rel="stylesheet" type="text/css"  />
    <link href="Login.css" rel="stylesheet" type="text/css"  />
    <link href="Default.css" rel="stylesheet" type="text/css"  />
    <link href="buttons.css" rel="stylesheet" type="text/css"  />
        
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
        <table id="Annex2">
          
   
           <thead class="tr1 tr1b">
            <th>Sl.No</th>
            <th>Name Of The Document</th>
            <th>Date</th>
            <th>File Name</th>
            <th>Upload</th>
            <th>Actions</th>
            <th>Delete</th>
            </thead>
        <tbody class="tr1">           
            <?php foreach($files as $file):
            $slno=$file['slno']; ?>
            <tr class="row">
                
                <td>
                    
                    <?php echo $file['slno'];?></td>
                <td>
                    <div contentEditable='true' class='edit' id='docname_<?php echo $slno; ?>'>
                    <?php echo $file['docname'];?></div></td>
                <td>
                    <div contentEditable='true' class='edit' id='dateofupload_<?php echo $slno; ?>'>
                    <?php echo $file['dateofupload'];?></div></td>
                <td>
                    <div contentEditable='true' class='edit' id='filename_<?php echo $slno; ?>'>
                    <?php echo $file['filename'];?></div></td>
               
                <td>
                     <a class="a4" href="uploadfileonly2.php?file_id=<?php echo $file['slno'];?>">Upload</a>                  
                </td>
                <td>
                 <a class="a3" href="Annexure2.php?file_id=<?php echo $file['id'];?>">Download</a>                   
                </td>
                <td><a href="javascript:void(0);" class="delete a2" data-id="<?php echo $file['slno']; ?>">Delete</a>
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
            url: 'delete2.php',
            data: {
                slno: _id
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
   url: 'update3.php',
   type: 'post',
   data: { field:field_name, value:value, id:edit_id },
   success:function(response){
    console.log('Save successfully'); 
   }
  });
 
 });

});
</script>


    </div>   
        
        <form  action="upload2.php">
        <button class="button2 button2a">Add</button>
        </form>
    </body>
    </html>

        


