<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
<head>
<meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
<title>无标题文档</title>
<style type="text/css">
<!--
body {
	margin-left: 3px;
	margin-top: 0px;
	margin-right: 3px;
	margin-bottom: 0px;
}
.STYLE1 {
	color: #e1e2e3;
	font-size: 12px;
}
.STYLE6 {color: #000000; font-size: 12; }
.STYLE10 {color: #000000; font-size: 12px; }
.STYLE19 {
	color: #344b50;
	font-size: 12px;
}
.STYLE21 {
	font-size: 12px;
	color: #3b6375;
}
.STYLE22 {
	font-size: 12px;
	color: #295568;
}
-->
</style>
<script>
	var  highlightcolor='#d5f4fe';
	//此处clickcolor只能用win系统颜色代码才能成功,如果用#xxxxxx的代码就不行,还没搞清楚为什么:(
	var  clickcolor='#51b2f6';
	function  changeto(){
	source=event.srcElement;
	if  (source.tagName=="TR"||source.tagName=="TABLE")
	return;
	while(source.tagName!="TD")
	source=source.parentElement;
	source=source.parentElement;
	cs  =  source.children;
	//alert(cs.length);
	if  (cs[1].style.backgroundColor!=highlightcolor&&source.id!="nc"&&cs[1].style.backgroundColor!=clickcolor)
	for(i=0;i<cs.length;i++){
		cs[i].style.backgroundColor=highlightcolor;
	}
	}
	
	function  changeback(){
	if  (event.fromElement.contains(event.toElement)||source.contains(event.toElement)||source.id=="nc")
	return
	if  (event.toElement!=source&&cs[1].style.backgroundColor!=clickcolor)
	//source.style.backgroundColor=originalcolor
	for(i=0;i<cs.length;i++){
		cs[i].style.backgroundColor="";
	}
	}
	
	function  clickto(){
	source=event.srcElement;
	if  (source.tagName=="TR"||source.tagName=="TABLE")
	return;
	while(source.tagName!="TD")
	source=source.parentElement;
	source=source.parentElement;
	cs  =  source.children;
	//alert(cs.length);
	if  (cs[1].style.backgroundColor!=clickcolor&&source.id!="nc")
		for(i=0;i<cs.length;i++){
			cs[i].style.backgroundColor=clickcolor;
		}
	else
		for(i=0;i<cs.length;i++){
			cs[i].style.backgroundColor="";
		}
	}
</script>
		
		<#include "common/common-js.ftl">
		<script>
			$(document).ready(function(){
				//单击删除链接执行的函数
				$(".delete").click(function(){
					
						//获取要删除的数据的ID
						var delId = $(this).attr("id");
						//获取要删除的行
						var delLine = $(this).parent().parent().parent();
						
						//弹出提示框，下面的function是单击"确定"按钮执行的函数
					    if(confirm("确定删除")){
							$.ajax({
								type:"GET",
								url:"/admin/logs/delete?logsId="+delId,
								dataType:"json",
								success:function(data){
								        alert("删除成功！");
									    delLine.remove();
								}
							})
					    }
				})
						
			})
		</script>
</head>

<body>
<table width="100%" border="0" align="center" cellpadding="0" cellspacing="0">
  <tr>
    <td height="30"><table width="100%" border="0" cellspacing="0" cellpadding="0">
      <tr>
        <td height="24" bgcolor="#353c44"><table width="100%" border="0" cellspacing="0" cellpadding="0">
          <tr>
            <td><table width="100%" border="0" cellspacing="0" cellpadding="0">
              <tr>
                <td width="15" height="19" valign="bottom">
                   <div align="center" style="text-indent:5px;"><img src="${base}/resource/images/tb.gif" width="14" height="14" /></div></td>
                <td valign="bottom"><span class="STYLE1">&nbsp;&nbsp;教师留言列表</span></td>
              </tr>
            </table></td>
            <td>
              
          </tr>
        </table></td>
      </tr>
    </table></td>
  </tr>
  <tr>
    <td class="list">
    	 <div style="font-size:13px;">
    	 <!--
         	<form action="${base}/admin/logs/list" method="post">
         		<table border=0 class="search">
         		   <tr>
         		   		<td>学年（学期）：
			         	   <select name="ytId">
			         	       <option value="0">请选择</option>
					  	 	   <#list ytList as yt>	
					  	 			<option value="${yt.SID}" <#if yt_id == yt.SID>selected</#if> >${yt.STUDY_YEAR_TERM}</option>
					  	 	   </#list>
					  	 	</SELECT>
         		   		<td>
         		   		<td>第
			         		 <select name="weekTh">
			         		 	<option value="0">请选择</option>
					  	 		<#list 1..20 as w>
					  	 			<option value="${w}" <#if y_week_th == w>selected</#if>>${w}</option>	
					  	 		</#list>
					  	 	</SELECT>
					  	 	周
         		   		<td>
         		   		<td>人员：
			         		 <select name="uid">
			         		    <option value=0>请选择</option>
					  	 		<#list mgnterList as m>
					  	 			<option value="${m.SID}" <#if userId == m.SID>selected</#if>>${m.UNAME}</option>	
					  	 		</#list>
					  	 	</SELECT>
         		   		<td>
         		   		<td>
         		   			<input type="submit" value=" 查找  ">  <input type="button" value=" 全部 " onclick="window.location.href='${base}/admin/logs/list'">
         		   		</td>
         		   		
         		   </tr>
         		</table>
         	</form>
         	-->
         </div>
         <form action="${base}/admin/logs/list" method="post" id="listForm">
            <input type="hidden" name="uid" value="${userId}">
            <input type="hidden" name="ytId" value="${yt_id}">
            <input type="hidden" name="weekTh" value="${y_week_th}">
	    	<table width="100%" border="0"  cellpadding="0" cellspacing="1" bgcolor="#a8c7ce" onmouseover="changeto()"  onmouseout="changeback()">
					       <tr>
							        <td width="4%" height="20" bgcolor="d3eaef">
								        <div align="center">
								          <input type="checkbox" name="checkbox" id="checkbox" class="selectAll" />
								          <script>
								          	  $(".selectAll").click(function(){
								          	  	  var recordIds = $(".record_id");
								          	  	  if($(this).attr("checked") == true){
								          	  	  	 for(var i = 0;i<recordIds.length;i++){
								          	  	  	 	$(recordIds[i]).attr("checked",true);
								          	  	  	 }
								          	  	  }else{
								          	  	  	 for(var i = 0;i<recordIds.length;i++){
								          	  	  	 	$(recordIds[i]).attr("checked",false);
								          	  	  	 }
								          	  	  }
								          	  })
								          </script>
								        </div>
							        </td>
									<td bgcolor="d3eaef" class="STYLE6"><div align="center"><span class="STYLE10">内容</span></div></td>
									<td bgcolor="d3eaef" class="STYLE6"><div align="center"><span class="STYLE10">回复</span></div></td>
									<td bgcolor="d3eaef" class="STYLE6"><div align="center"><span class="STYLE10">时间</span></div></td>
									<td bgcolor="d3eaef" class="STYLE6"><div align="center"><span class="STYLE10">处理人</span></div></td>
									<td bgcolor="d3eaef" class="STYLE6"><div align="center"><span class="STYLE10">操作</span></div></td>
									
					       </tr>
			          <#list msgList as list>
							<tr>
									    <td width="4%" height="20" bgcolor="#FFFFFF" style="border-right:0px;">
										        <div align="center">
										          <input type="checkbox" name="checkbox" id="checkbox" class="record_id"  value="${list.sid}"/>
										        </div>
							       		</td>
						       		  	<td bgcolor="#FFFFFF" class="STYLE19" style="width:300px;"><div align="center">${list.content}</div></td>
						       		  	<td bgcolor="#FFFFFF" class="STYLE19"><div align="center"><#if list.answer?length gt 100>${list.answer[0..100]}<#else>${list.answer}</#if></div></td>
						       		  	<td bgcolor="#FFFFFF" class="STYLE19"><div align="center"><#if list.ctime??>${list.ctime?string("yyyy-MM-dd")}</#if></div></td>
						       		  	<td bgcolor="#FFFFFF" class="STYLE19"><div align="center"><#if list.user??>${list.user.UNAME}</#if></div></td>
						       		  	<td bgcolor="#FFFFFF" class="STYLE19">
						       		  		<div align="center">
						       		  		  <#if !list.answer??><img src="${base}/resource/images/index1_68.gif"> <a href="${base}/admin/leave_msg/answer?msgId=${list.sid}">回复</a></#if>
						       		  	    </div>
						       		    </td>
							</tr>
				     </#list>
		    </table>
		    <div class="pagerBar">
		    		<div align='left' style='float:left'><span class='STYLE22'>共有<strong>${pager.totalCount!0}</strong> 条记录，当前第<strong> ${pager.pageNumber!0}</strong> 页，共 <strong>${pager.pageCount!0}</strong> 页</span></div>
		    		<#include "common/pager.ftl">
			</div>
		</form>
	 </td>
  </tr>
  <tr>
    <td height="30"></td>
      </tr>
    </table></td>
  </tr>
</table>

</body>
</html>