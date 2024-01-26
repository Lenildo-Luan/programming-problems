<?php

/*

==========  LENILDO LUAN CARLOS  ==========
========== LENILDOLUAN@GMAIL.COM ==========

Question: https://www.beecrowd.com.br/judge/en/problems/view/2754

1. Try to use number_format()
2. Change to printf()
3. Printf show scientif number with 1 digit exponential without zero before the digit
4. Use variadic function, regex and substr_replace to add the zero before the digit

*/

// Variadic function
function scientificNumbersFormat(&...$numbers) {
    $len = count($numbers);
    
    for($i = 0; $i < $len; $i++) {
        // Check if the exponent part is a single digit
        if (preg_match('/e|E[\+\-]?\d$/', $numbers[$i])) {
            // Add a zero before the last digit
            $numbers[$i] = substr_replace($numbers[$i], '0', -1, 0);
        }
    }
}

$real1 = 234.345;
$real2 = 45.698;

echo sprintf("%.6f", $real1), ' - ', sprintf("%.6f", $real2), "\n";
echo sprintf("%.0f", $real1), ' - ', sprintf("%.0f", $real2), "\n";
echo sprintf("%.1f", $real1), ' - ', sprintf("%.1f", $real2), "\n";
echo sprintf("%.2f", $real1), ' - ', sprintf("%.2f", $real2), "\n";
echo sprintf("%.3f", $real1), ' - ', sprintf("%.3f", $real2), "\n";

$formattedReal1 = sprintf("%e", $real1);
$formattedReal2 = sprintf("%e", $real2);
scientificNumbersFormat($formattedReal1, $formattedReal2);
echo $formattedReal1, ' - ', $formattedReal2, "\n";

$formattedReal1 = sprintf("%E", $real1);
$formattedReal2 = sprintf("%E", $real2);
scientificNumbersFormat($formattedReal1, $formattedReal2);
echo $formattedReal1, ' - ', $formattedReal2, "\n";

echo sprintf("%g", $real1), ' - ', sprintf("%g", $real2), "\n";
echo sprintf("%G", $real1), ' - ', sprintf("%G", $real2), "\n";

?>
