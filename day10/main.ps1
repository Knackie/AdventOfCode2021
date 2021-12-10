[System.Collections.ArrayList]$linescores= @()

#): 1 points
#]: 2 points
#}: 3 points
#>: 4 points



foreach($line in Get-Content .\input.txt) {
	[System.Collections.ArrayList]$openingchars= @()
	$valide = 1

	For($i=0;$i -lt $line.length;$i++) {

		if($valide -eq 0){
			break
		}

		if($line[$i] -eq '(' -Or $line[$i] -eq '[' -Or $line[$i] -eq '{' -Or $line[$i] -eq '<'){
			
			$openingchars.Add($line[$i]) | Out-Null
			
		}

		elseif($line[$i] -eq ')'){
			if($openingchars[$openingchars.Count – 1] -eq '('){
				$openingchars.RemoveAt($openingchars.Count – 1)
			}
			else{
				$valide = 0
			}
		}

		elseif($line[$i] -eq ']'){
			if($openingchars[$openingchars.Count – 1] -eq '['){
				$openingchars.RemoveAt($openingchars.Count – 1)
			}
			else{
				$valide = 0
			}
		}

		elseif($line[$i] -eq '}'){
			if($openingchars[$openingchars.Count – 1] -eq '{'){
				$openingchars.RemoveAt($openingchars.Count – 1)
			}
			else{
				$valide = 0
			}
		}

		elseif($line[$i] -eq '>'){
			if($openingchars[$openingchars.Count – 1] -eq '<'){
				$openingchars.RemoveAt($openingchars.Count – 1)
			}
			else{
				$valide = 0
			}
		}
	}

	if($valide -eq 1){
		$linescore = 0
		$l = $openingchars.Count
		For($i=0;$i -lt $l;$i++) {
			
		$linescore = 5 * $linescore
		 

			if($openingchars[$openingchars.Count – 1] -eq '('){
				$linescore = $linescore + 1
			}
			elseif($openingchars[$openingchars.Count – 1] -eq '['){
				$linescore = $linescore + 2
			}
			elseif($openingchars[$openingchars.Count – 1] -eq '{'){
				
				$linescore = $linescore + 3
				
			}
			elseif($openingchars[$openingchars.Count – 1] -eq '<'){
				$linescore = $linescore + 4
			}

			$openingchars.RemoveAt($openingchars.Count – 1)

		}
		$linescores.Add($linescore) | Out-Null
	}	

}

$linescores = $linescores | sort

$score = $linescores[$linescores.count/2 - 0.5]
echo $score
