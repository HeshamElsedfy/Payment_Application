<?xml version="1.0" encoding="UTF-8" standalone="yes" ?>
<CodeBlocks_project_file>
	<FileVersion major="1" minor="6" />
	<Project>
		<Option title="Payment Application" />
		<Option pch_mode="2" />
		<Option compiler="gcc" />
		<Build>
			<Target title="Debug">
				<Option output="bin/Debug/Payment Application" prefix_auto="1" extension_auto="1" />
				<Option object_output="obj/Debug/" />
				<Option type="1" />
				<Option compiler="gcc" />
				<Compiler>
					<Add option="-g" />
				</Compiler>
			</Target>
			<Target title="Release">
				<Option output="bin/Release/Payment Application" prefix_auto="1" extension_auto="1" />
				<Option object_output="obj/Release/" />
				<Option type="1" />
				<Option compiler="gcc" />
				<Compiler>
					<Add option="-O2" />
				</Compiler>
				<Linker>
					<Add option="-s" />
				</Linker>
			</Target>
		</Build>
		<Compiler>
			<Add option="-Wall" />
		</Compiler>
		<Unit filename="Application/app.c">
			<Option compilerVar="CC" />
		</Unit>
		<Unit filename="Application/app.h" />
		<Unit filename="Card/card.c">
			<Option compilerVar="CC" />
		</Unit>
		<Unit filename="Card/card.h" />
		<Unit filename="Server/server.c">
			<Option compilerVar="CC" />
		</Unit>
		<Unit filename="Server/server.h" />
		<Unit filename="Terminal/terminal.c">
			<Option compilerVar="CC" />
		</Unit>
		<Unit filename="Terminal/terminal.h" />
		<Extensions />
	</Project>
</CodeBlocks_project_file>