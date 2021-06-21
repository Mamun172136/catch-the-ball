                           

 Members:
Name: Abdullah-Al-Mamun
Id: 011172136
Name: Md.Sajibur Rahman
Id: 011172152
Name: Munna Ahamed
Id: 01172146
Submitted By: Abdullah-Al-Mamun
Submitted To: Mohammad Tawhidul Hasan Bhuiyan



                                                  Documantation

drawSphere(): Here in this function we create the ball. We create circle and are taking four points for making quads.
Just_line(): Here we make basket. We create 3 lines – green line, red line, yellow line. 
Showscore(): In this function we displayed score. glutBitmapCharacter renders a bitmap character using OpenGL. We used sprint function though score is integer but we print as string. We used glcolor for text color. We used glRasterpos3f() for position set.
Showlife ( ): Here in this function we displayed life. How many life user has. We used glcolor for text color. We used glRasterpos3f() for position set. glutBitmapCharacter renders a bitmap character using OpenGL. We used sprint function though score is integer but we print as string.
Showlevel ( ) : In this function we displayed level. glutBitmapCharacter renders a bitmap character using OpenGL. We used sprint function though level is integer but we print as string. We used glcolor  for text color. We used glRasterpos3f() for position set.
restart_msg_show ( ) : Here we displayed message “ please press r for restart game”.
All_message( ) : Here we displayed message “press  s for start the game”,” Catch The Ball”
Starting_menu( ) : From this function we called all_message() function. At the beginning of the game user will see all message and ball and basket. So in this function we drew a ball and basket.
Checked( ) : Here in this function we set check variable 0;We set also ball position again. This function wil call when user has life but he missed a ball to catch.
Game( ) : Here in this function we called showscore, showlife, showlevel. Here we checked game over condition. Game over condition will be true when ball is below -1.8 and  ball is less than basket left hand – 0.3 or ball is below -1.8 and  ball is more than basket right hand +0.3. Life is greater than 0 we call function checked(). Otherwise we call function restart_message(). If check variable is 0 game is running. So we checked check variable is 1 or 0. If check variable is 0 we deduct value of  objy that’s means we took ball below. If objy(ball height) is below -1.85 we set ball position anew cause ball is bottom at the screen. So for setting ball position we took help random function. We take the between 1.8 and 1.8 and set objx(ball x). If score is 5 multiple we increase level 1 and speed life also. Then we drew ball and basket. After drawing ball we translate the ball 

specialkeyListener(): Here we move basket using left and right key. If we press right key basket will move right hand press left basket will move left. If basx is less than 1.6 we increase basx 0.3 and can move right. If basx is greater than -1.41 we deduct basx 0.3 and can move left.
keyboardListener(): Here if user press s game will start. We set ball position, life ,speed , level. If user press r game will restart again we need to set ball position, life ,speed , level.

mouseListener(): If user press left basket move left and press right basket move right. Here we checked if game is running and basket is greater than -1.41 then basket can go left and game is running basket is less than 1.6 then basket can go right.

Main(): from this function we actually call others function .here we set window size.We set title as “ catch the ball”. We called glutSpecialFunc , glutKeyboardFunc, glutDisplayFunc.

Global variable : For showing score we use  variable such as s1x,s2x,s2x,s2y.Using this variable we fixed position of screen. For showing life we used lfx1, lfx2, lf2x1, lf2y2 these variable. We used check variable for checking game is running or off. If check variable is 0, game is on. We used life variable for setting life. We used level variable setting level. We used speed variable for increasing speed. We used basx basy for positioning basket x and y. We used obx oby for positioning ball x and y. Using score variable we displayed score. Using a, b, c we set color. Using 11x, 11y, 12x, 12y variable we set position of level.
