def genHtmlProblem(param):return """
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/prism/1.26.0/themes/prism-tomorrow.min.css" integrity="sha512-vswe+cgvic/XBoF1OcM/TeJ2FW0OofqAVdCZiEYkd6dwGXthvkSFWOoGGJgS2CW70VK5dQM5Oh+7ne47s74VTg==" crossorigin="anonymous" referrerpolicy="no-referrer" />
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/prism/1.26.0/plugins/line-numbers/prism-line-numbers.min.css" integrity="sha512-cbQXwDFK7lj2Fqfkuxbo5iD1dSbLlJGXGpfTDqbggqjHJeyzx88I3rfwjS38WJag/ihH7lzuGlGHpDBymLirZQ==" crossorigin="anonymous" referrerpolicy="no-referrer" />
<link rel="preconnect" href="https://fonts.googleapis.com">
<link rel="preconnect" href="https://fonts.gstatic.com" crossorigin>
<link href="https://fonts.googleapis.com/css2?family=Cabin" rel="stylesheet">
<link href="https://fonts.googleapis.com/css2?family=Source+Code+Pro" rel="stylesheet">
<link rel="stylesheet" type="text/css" href="../styles.css">

<style type="text/css">
	body{
		padding: 25px 50px 25px 50px;
		font-family: 'Cabin';
	}
	a{
		color: #38A3A5;
		text-decoration: underline;
	}
	div{
		margin-bottom: 15px;
	}
	code, code[class*=language-], pre[class*=language-]{
		font-family: 'Source Code Pro';
	}
</style>

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
	<title></title>
	<meta charset="utf-8">
	<meta name="viewport" content="width=device-width, initial-scale=1.0">
	<link rel="preconnect" href="https://fonts.googleapis.com">
	<link rel="preconnect" href="https://fonts.gstatic.com" crossorigin>
	<link href="https://fonts.googleapis.com/css2?family=Cabin" rel="stylesheet">
	<link href="https://fonts.googleapis.com/css2?family=Fugaz+One" rel="stylesheet">
	<link rel="stylesheet" type="text/css" href="styles.css">

	<script>
	function loadHtml(filename){
		document.getElementById('content').innerHTML = '<iframe class="iframe" frameborder="0" src="'+filename+'">';
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