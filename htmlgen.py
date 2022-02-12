def genHtmlProblem(param):return """
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/prism/1.26.0/themes/prism-tomorrow.min.css" integrity="sha512-vswe+cgvic/XBoF1OcM/TeJ2FW0OofqAVdCZiEYkd6dwGXthvkSFWOoGGJgS2CW70VK5dQM5Oh+7ne47s74VTg==" crossorigin="anonymous" referrerpolicy="no-referrer" />
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/prism/1.26.0/plugins/line-numbers/prism-line-numbers.min.css" integrity="sha512-cbQXwDFK7lj2Fqfkuxbo5iD1dSbLlJGXGpfTDqbggqjHJeyzx88I3rfwjS38WJag/ihH7lzuGlGHpDBymLirZQ==" crossorigin="anonymous" referrerpolicy="no-referrer" />
<link rel="preconnect" href="https://fonts.googleapis.com">
<link rel="preconnect" href="https://fonts.gstatic.com" crossorigin>
<link href="https://fonts.googleapis.com/css2?family=Cabin" rel="stylesheet">
<link href="https://fonts.googleapis.com/css2?family=Source+Code+Pro" rel="stylesheet">
<link rel="stylesheet" type="text/css" href="../styles.css">
<link rel="stylesheet" type="text/css" href="../content.css">

<body>
<div class="card">
	<h2>Problem: %s</h2>
	<br>
	<div>
		<b>Solution Contributor:</b> <a target="_blank" href="https://github.com/DecSP">Cao Son Nguyen</a>.<br>
		<a target="_blank" href="%s">View on CSES</a>
	</div>

	
	<h3>Code</h3>
	<ul>
		<pre class="line-numbers">%s</pre>
	</ul>
</div>



<script src="https://cdnjs.cloudflare.com/ajax/libs/prism/1.26.0/components/prism-core.min.js"></script>
<script src="https://cdnjs.cloudflare.com/ajax/libs/prism/1.26.0/plugins/autoloader/prism-autoloader.min.js"></script>
<script src="https://cdnjs.cloudflare.com/ajax/libs/prism/1.26.0/plugins/line-numbers/prism-line-numbers.min.js" integrity="sha512-dubtf8xMHSQlExGRQ5R7toxHLgSDZ0K7AunqPWHXmJQ8XyVIG19S1T95gBxlAeGOK02P4Da2RTnQz0Za0H0ebQ==" crossorigin="anonymous" referrerpolicy="no-referrer"></script>
</body>

"""%param
def genHtmlIndex(sidebar):
	re=""
	for cate in sidebar:
		tmp="<summary>%s</summary>"%cate
		for title in sidebar[cate]:
			tmp+="""<li><a href="Javascript:void(0);" id="about" onclick="loadHtml('%s/%s.html')">%s</a></li>\n"""%(cate,title,title)
		re+="<details>%s</details>"%tmp
	return """
<!DOCTYPE html>
<html>
<head>
	<title>CSES Sols</title>
	<meta name="theme-color" content="#57CC99">
	<meta property="og:image" content="public/og.png"/>
	<meta property="og:type" content="website"/>
	<meta property="og:url" content="https://csessolutions.netlify.app/"/>
	<meta property="og:title" content="CSES Solutions"/>
	<meta property="og:description" content="We provide our solutions for coding problems of CSES site that is owned by Antti Laaksonen & Topi Talvitie during our data structures and algorithms learning. Most of the solutions are written in C++ and Python programming language."/>
	<link rel="icon" href="public/icon.png">
	<meta charset="utf-8">
	<meta name="viewport" content="width=device-width, initial-scale=1.0">
	<link rel="preconnect" href="https://fonts.googleapis.com">
	<link rel="preconnect" href="https://fonts.gstatic.com" crossorigin>
	<link href="https://fonts.googleapis.com/css2?family=Cabin" rel="stylesheet">
	<link href="https://fonts.googleapis.com/css2?family=Fugaz+One" rel="stylesheet">
	<link rel="stylesheet" href="https://pro.fontawesome.com/releases/v5.10.0/css/all.css" integrity="sha384-AYmEC3Yw5cVb3ZcuHtOA93w35dYTsvhLPVnYs9eStHfGJvOvKxVfELGroGkvsg+p" crossorigin="anonymous"/>
	<link rel="stylesheet" type="text/css" href="styles.css">

	<script>
	function loadHtml(filename){
		document.getElementById('content').innerHTML = '<iframe class="iframe" frameborder="0" src="'+filename+'">';
	}
	function clearNav(){
		document.getElementById('home').style.textDecoration="none";
		document.getElementById('about').style.textDecoration="none";
	}
	function setNav(id){
		if(id === 'home'){
			document.getElementById('home').style.textDecoration="underline";
		}
		if(id === 'contact'){
			document.getElementById('about').style.textDecoration="underline";
		}
	}
	var open = 0;
	if(screen.width <= 670){
		document.getElementById('sidebar').style.display="none";
	}
	function showSidebar(){
		open++;
		if(open%2 ==1){
			document.getElementById('sidebar').style.display="block";
		}
		else if(open%2 == 0){
			document.getElementById('sidebar').style.display="none";
		}
	}
	</script>
</head>
<body>
	<div class="header">
		<a href="Javascript:void(0);"><span>CSES Algo...</span></a>
		<div class="navbar">
			<a href="Javascript:void(0);" id="about" onclick="loadHtml('about.html')">About us</a>

		</div>
	</div>
	<div id="main">
		<div class="sidebar" id="sidebar">
			%s
		</div>
		<div class="content" id="content">

		</div>
	</div>
</body>

</html>
"""%re
