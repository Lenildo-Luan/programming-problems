<?php

/*

==========  LENILDO LUAN CARLOS  ==========
========== LENILDOLUAN@GMAIL.COM ==========

Question: https://www.beecrowd.com.br/judge/en/problems/view/2936

My first code on PHP :D

*/

$cassavaGrams = 0;
$curupiraPotions = readline();
$boitataPotions = readline();
$botoPotions = readline();
$mapinguariPotions = readline();
$iaraPotions = readline();
$donaChica = 225;

$cassavaGrams += $curupiraPotions * 300;
$cassavaGrams += $boitataPotions * 1500;
$cassavaGrams += $botoPotions * 600;
$cassavaGrams += $mapinguariPotions * 1000;
$cassavaGrams += $iaraPotions * 150;
$cassavaGrams += $donaChica;

echo $cassavaGrams, "\n";

?>
