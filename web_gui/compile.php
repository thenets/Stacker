<?php
// Remove old files
exec("rm word.txt stack.txt out.txt");


// Create word 
$fp = fopen('word.txt', 'w');
fwrite($fp, $_GET['word']);
fclose($fp);


// Create stack
$fp = fopen('stack.txt', 'w');
fwrite($fp, $_GET['stack']);
fclose($fp);


// Compile
exec("./stacker >> out.txt 2>&1");

//sleep(1);

// Output
header('Content-Type: application/json');
$fp = fopen("out.txt", "r") or die("Unable to open file!");
$out = fread($fp,filesize("out.txt"));
fclose($fp);
$out = str_replace("\n", "<br>", $out);
$out = str_replace(" ", "&nbsp;", $out);
echo '{"output": "'.$out.'"}';


// Remove old files
//exec("rm word.txt stack.txt out.txt");