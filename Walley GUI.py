from tkinter import *
#import serial

LARGEFONT =("Verdana", 35)
MEDIUMFONT=("Verdana",20)

# creates the connection for serial transmission
# bluetooth = serial.Serial("/dev/rfcomm0", baudrate=9600)


# class to implement bluetooth controls from the buttons.
# dropped due to time and countless errors trying to get bluetooth/serial connection to work.

# class Process():
#     def __init__(self, button):
#         self.button = button

#     def button_process(self, button):
        
#         # assigns the value to be sent serially to the arduino
#         # based on the button pressed
#         try:
#             if button == "Clean":
#                 value = 1

#             if button == "Up":
#                 value = 2

#             if button == "Down":
#                 value = 3

#             if button == "Left":
#                 value = 4

#             if button == "Right":
#                 value = 5
            
#             s = str(value)
#             b = s.encode()
#             bluetooth.write(b)
#         except KeyboardInterrupt:
#             print("error")
#             bluetooth.close()

            # converts the int value to str then enocdes the str value into byte
            
        # Recives info from arduino as bytes and decripts it into str value
        # RXD = (bluetooth.readline()).strip().decode("utf-8")
        # print(RXD)


class tkinterApp(Tk):
    # __init__ function for class tkinterApp
    def __init__(self, *args, **kwargs):        
        Tk.__init__(self, *args, **kwargs)
        # creating a container
        container = Frame(self)
        container.pack(side = "top", fill = "both", expand = True)
        container.grid_rowconfigure(0, weight = 1)
        container.grid_columnconfigure(0, weight = 1)

        # initializing frames to an empty array
        self.frames = {}

        # iterating through a tuple consisting
        # of the different pages
        for F in (StartPage, Page1, Page2):
            frame = F(container, self)

            # initializing frame of that object from
            # startpage, page1, page2 respectively
            self.frames[F] = frame
            frame.grid(row = 0, column = 0, sticky ="nsew")
        self.show_frame(StartPage)

    # to display the current frame
    def show_frame(self, cont):
        frame = self.frames[cont]
        frame.tkraise()


# first window frame
# contains the main page contents.
class StartPage(Frame):
    def __init__(self, parent, controller):
        Frame.__init__(self, parent)

        # label of frame Layout 2
        label = Label(self, text ="Whiteboard Walley", font = LARGEFONT, fg = "blue")
        label.place(x=170, y=50)
        button1 = Button(self, text ="Automatic", command = lambda : controller.show_frame(Page1))
        button1.grid(row = 1, column = 1, padx = 10, pady = 10)

        # button to show frame 2 with text layout2
        button2 = Button(self, text ="Manual", command = lambda : controller.show_frame(Page2))
        button2.grid(row = 2, column = 1, padx = 10, pady = 10)

        # create an Image object
        img = PhotoImage(file="tech.gif")
        # create a label in order to present the Image object
        Techlogo = Label(self, image=img)
        Techlogo.image = img
        Techlogo.place(x=625, y=300)

        #louisiana label
        louisiana = Label(self, text="Louisiana", font=MEDIUMFONT, fg="red")
        louisiana.place(x=325, y=340)

        #tech label
        tech = Label(self, text="Tech", font=MEDIUMFONT, fg="blue")
        tech.place(x=350, y=375)

        #champ pic Image
        img = PhotoImage(file="champ.gif")
        # create a label in order to present the Image object
        Champlogo = Label(self, image=img)
        Champlogo.image = img
        Champlogo.place(x=10, y=150)


        
# second window frame
# contains the automatic profile
class Page1(Frame):
    def __init__(self, parent, controller):
        Frame.__init__(self, parent)
        label = Label(self, text ="Automatic", font = LARGEFONT)
        label.place(x=260,y=0)

        # button to transition to main page again
        button1 = Button(self, text ="Whiteboard Walley", command = lambda : controller.show_frame(StartPage))
        button1.grid(row = 1, column = 1, padx = 10, pady = 10)

        # button used to transition to the manual settings
        button2 = Button(self, text ="Manual", command = lambda : controller.show_frame(Page2))
        button2.grid(row = 2, column = 1, padx = 10, pady = 10)

        # button that is used to start the automatic cleaning cycle
        Auto = Button(self, text = "   Clean   ", bg="black", fg="white") #, command=lambda : self.process("Clean"))
        Auto.place(x =  360, y = 150)

        # adds the tech logo to this page
        img = PhotoImage(file="tech.gif")
        Techlogo = Label(self, image = img)
        Techlogo.image = img
        Techlogo.place(x=625, y=300)


# third window frame page2
# contains the manual profile
class Page2(Frame): #, Process):
    def __init__(self, parent, controller):
        Frame.__init__(self, parent)
        label = Label(self, text ="Manual", font = LARGEFONT)
        label.place(x=300,y=0)
        # Process.__init__(self, button)
        # button = self.button

        # button used to switch to the automatic page
        button1 = Button(self, text ="Automatic", command = lambda : controller.show_frame(Page1))
        button1.grid(row = 1, column = 1, padx = 10, pady = 10)

        # button that sends the user back to the main page
        button2 = Button(self, text ="Whiteboard Walley", command = lambda : controller.show_frame(StartPage))
        button2.grid(row = 2, column = 1, padx = 10, pady = 10)

        # these buttons control the manual movement of the robot
        Up = Button(self, text = "UP", height = 1, width = 5, bg="black", fg="white") #, command=lambda: self.procces("Up"))
        Up.place(x = 360,y = 100)

        Down = Button(self, text = "DOWN", height = 1, width = 5, bg="black", fg="white") #, command=lambda: self.procces("Down"))
        Down.place(x = 360,y = 125)

        Left = Button(self, text = "LEFT", height = 1, width = 5, bg="black", fg="white") #, command=lambda: self.process("Left"))
        Left.place(x = 295,y = 125)

        Right = Button(self, text = "RIGHT", height = 1, width = 5, bg="black", fg="white") #, command=lambda: self.process("Right"))
        Right.place(x = 425,y = 125)

        # adds the Tech logo to this page
        img = PhotoImage(file="tech.gif")
        Techlogo = Label(self, image=img)
        Techlogo.image = img
        Techlogo.place(x=625, y=300)


# Driver Code
app = tkinterApp()
app.geometry("800x425") # Width x Height
app.mainloop()
