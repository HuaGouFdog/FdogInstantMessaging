package com.fdog;
import com.fdogrand.*;
import java.io.IOException;
import java.io.PrintWriter;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;

import javax.servlet.ServletException;

import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
//发送验证码的servlet
import com.tencentcloudapi.common.Credential;
import com.tencentcloudapi.common.exception.TencentCloudSDKException;
import com.tencentcloudapi.common.profile.ClientProfile;
import com.tencentcloudapi.sms.v20190711.SmsClient;
import com.tencentcloudapi.sms.v20190711.models.SendSmsRequest;
import com.tencentcloudapi.sms.v20190711.models.SendSmsResponse;
/**
 * Servlet implementation class AuthCode
 */
public class AuthCode extends HttpServlet {
	private static final long serialVersionUID = 1L;
	String username="";
	String password="";
	String phone = "";
    /**
     * @see HttpServlet#HttpServlet()
     */
    public AuthCode() {
        super();
        // TODO Auto-generated constructor stub
    }

	/**
	 * @see HttpServlet#doGet(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		// TODO Auto-generated method stub
		
		//response.getWriter().append("Served at: ").append(request.getContextPath());
		response.setContentType("text/html;charset=utf-8");
	}

	/**
	 * @see HttpServlet#doPost(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		// TODO Auto-generated method stub
		request.setCharacterEncoding("UTF-8");
		response.setContentType("text/html;charset=utf-8");
		//request.getRequestDispatcher("index.jsp").forward(request,response);
		phone 	= request.getParameter("phone");
		username = request.getParameter("username");
		password = request.getParameter("password");
		request.setAttribute("phone",phone);
		request.setAttribute("username",username);
		request.setAttribute("password",password);
		//System.out.println("你好"+phone);
		Rand num = new Rand();
		int randnum = num.ReturnRandNumer();
		phone 	= request.getParameter("phone");
		PrintWriter printWriter = response.getWriter(); //获得输出流对象
		printWriter.print("随机码为"+randnum+"   "+"手机号:"+phone);
		System.out.println("AuthCode生成的验证码为："+randnum+"昵称:"+username);
		//验证手机号，正确则发送验证码
		//加载驱动程序
		try {
			Class.forName("com.mysql.jdbc.Driver");
			System.out.print("驱动程序加载成功,");
		} catch (ClassNotFoundException e) {
			e.printStackTrace();
		}
		//链接数据库
		String str = "jdbc:mysql://0.0.0.0:3306/fdogsql?useUnicode=true&characterEncoding=UTF-8&userSSL=false&serverTimezone=GMT%2B8";	
		Connection conn=null;
		try {
			conn=DriverManager.getConnection(str,"root","1111111");
			if (!conn.isClosed()) {
				System.out.println("连接数据库成功");
			}
		} catch (SQLException e) {
			System.out.println("链接数据库失败: "+e.getMessage());
		}
		//数据库查询
		int zc =0;
		try{
		Statement stmt = conn.createStatement();
	    ResultSet rs = stmt.executeQuery("select * from user");
        while(rs.next()){//如果对象中有数据，就会循环打印出来
	          if(phone.equals(rs.getString("phone"))) {
	        	  zc = 1;
	          }
      }
		}catch(SQLException e){
			System.out.println("查询失败");
		}		
		if(zc==1) {
			System.out.println("该手机号已经注册");
			PrintWriter pw=response.getWriter();
			pw.write("<script language='javascript'>alert('弹出内容')</script>");
		}
		else{
			System.out.println("短信已发送");
			String secretId = "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx";
			String secretKey= "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx";
			//短信应用 ID
			String appid = "xxxxxxxx";
			//短信签名内容
			String sign = "花狗的小站";
			//短信模板 ID
			String templateID = "xxxxxx";
			//+86为国家码，182********为手机号，最多不要超过200个手机号
			String[] phoneNumbers = { "+86"+phone};
			//模板参数: 若无模板参数，则设置为空
			String[] templateParams = {String.valueOf(randnum)};//对应模板中{1}
			try {
				//必要步骤： 实例化一个认证对象，入参需要传入腾讯云账户密钥对 secretId 和 secretKey
				Credential cred = new Credential(secretId , secretKey);
	 
				ClientProfile clientProfile = new ClientProfile();
				//SDK 默认用 TC3-HMAC-SHA256 进行签名 非必要请不要修改该字段
				 
				clientProfile.setSignMethod("HmacSHA256");
				// 实例化 SMS 的 client 对象 第二个参数是地域信息，可以直接填写字符串 ap-guangzhou，或者引用预设的常量
				SmsClient client = new SmsClient(cred, "", clientProfile);
				//实例化一个请求对象，根据调用的接口和实际情况，可以进一步设置请求参数 您可以直接查询 SDK 源码确定接口有哪些属性可以设置
				SendSmsRequest req = new SendSmsRequest();
	
				// 短信应用 ID: 在 [短信控制台] 添加应用后生成的实际 SDKAppID，例如1400006666 
				req.setSmsSdkAppid(appid);
	
				// 短信签名内容: 使用 UTF-8 编码，必须填写已审核通过的签名，可登录 [短信控制台] 查看签名信息 
				req.setSign(sign);
	
				//短信模板 ID: 必须填写已审核通过的模板 ID，可登录 [短信控制台] 查看模板 ID 
				req.setTemplateID(templateID);
	
				//下发手机号码，采用 e.164 标准，+[国家或地区码][手机号] 例如+8613711112222
				req.setPhoneNumberSet(phoneNumbers);
				
				req.setTemplateParamSet(templateParams);
	
				// 通过 client 对象调用 SendSms 方法发起请求。注意请求方法名与请求对象是对应的 返回的 res 是一个SendSmsResponse 类的实例，与请求对象对应
				SendSmsResponse res = client.SendSms(req);
	
				// 输出 JSON 格式的字符串回包
				System.out.println(SendSmsResponse.toJsonString(res));
	
				// 可以取出单个值，您可以通过官网接口文档或跳转到 response 对象的定义处查看返回字段的定义
				System.out.println(res.getRequestId());
	
			} catch (TencentCloudSDKException e) {
				e.printStackTrace();
			}
		}
		
		this.getServletContext().setAttribute("fp", String.valueOf(randnum));
		request.getRequestDispatcher("index.jsp").forward(request,response);
		//doGet(request, response);
	}

}
