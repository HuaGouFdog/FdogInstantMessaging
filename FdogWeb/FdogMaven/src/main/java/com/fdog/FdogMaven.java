package com.fdog;

import java.sql.*;

import java.io.IOException;
import java.io.PrintWriter;

import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import com.fdogrand.*;
public class FdogMaven extends HttpServlet {
	private static final long serialVersionUID = 1L;
	String value;
    /**
     * @see HttpServlet#HttpServlet()
     */
    public FdogMaven() {
        super();
        // TODO Auto-generated constructor stub
    }

	/**
	 * @see HttpServlet#doGet(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {

	}
	/**
	 * @see HttpServlet#doPost(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		

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
				try{
				Statement stmt = conn.createStatement();
			    ResultSet rs = stmt.executeQuery("select * from user");
		        while(rs.next()){//如果对象中有数据，就会循环打印出来
			          //System.out.println(rs.getString("name")+"    "+rs.getString("password"));
		      }
				}catch(SQLException e){
					System.out.println("查询失败");
				}		
		request.setCharacterEncoding("UTF-8");
		response.setContentType("text/html;charset=utf-8");
		String username = request.getParameter("username");
		String password = request.getParameter("password");
		String phone = request.getParameter("phone");
		//生成用户账户
		Rand num = new Rand();
		String account = String.valueOf(num.ReturnRandNumer_2());
		String verificationcode = request.getParameter("verificationcode");
		PrintWriter printWriter = response.getWriter(); //获得输出流对象
		printWriter.print("post昵称"+username+"  密码"+password+"手机号"+phone+"\n");
		System.out.print("用户账户： "+account+"  用户昵称   "+username+"  设置密码     "+password+"   注册手机号  "+phone+"   用户输入的验证码"+verificationcode+"\n");
		value = (String) this.getServletContext().getAttribute("fp");
		printWriter.print("随机码为"+value);
		System.out.println("终端接受的验证码为："+value);
		//response.getOutputStream().write(value.getBytes());
		//request.setAttribute("account",account);
		//System.out.println("account为："+account);
		//request.setAttribute("phone",phone);
		//request.setAttribute("username",username);
		//request.setAttribute("password",password);
		if(value.equals(request.getParameter("verificationcode"))) {
			System.out.println("验证码输入正确，写入数据库");
			//写入数据库
			try{
			String sql="insert into user(account,phone,name,password) values("+"'"+account+"',"+"'"+phone+"',"+"'"+username+"',"+"'"+password+"'"+")"; 
			Statement stmt = conn.createStatement();
			stmt.executeUpdate(sql);
			System.out.println("写入成功");
			
			//调用注册成功页面
			request.setAttribute("account", account);  //保存账户
			request.setAttribute("phone", phone);  //保存手机
			request.getRequestDispatcher("success.jsp").forward(request,response);
			}catch(SQLException e){
				System.out.println("写入失败");
			}	
		}
		else {
			request.getRequestDispatcher("index.jsp").forward(request,response);
			//PrintWriter pw=response.getWriter();
			//pw.write("<script language='javascript'>alert('验证码错误')</script>");
		}
		doGet(request, response);
	}

}
